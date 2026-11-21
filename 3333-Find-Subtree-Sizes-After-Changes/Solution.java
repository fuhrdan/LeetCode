import java.util.Arrays;

class Solution {
    public int[] findSubtreeSizes(int[] parent, String s) {
        int n = parent.length;
        int[] head = new int[n];
        int[] next = new int[n];
        Arrays.fill(head, -1);
        for (int u = 1; u < n; u++) {
            next[u] = head[parent[u]];
            head[parent[u]] = u;
        }

        int[] nearest = new int[26];
        Arrays.fill(nearest, -1);
        int[] previous = new int[n];
        int[] newParent = new int[n];
        int[] order = new int[n];
        int[] events = new int[2 * n];
        char[] label = s.toCharArray();

        int top = 0, count = 0;
        events[top++] = 0;
        while (top > 0) {
            int event = events[--top];
            if (event >= 0) {
                int u = event;
                int c = label[u] - 'a';
                previous[u] = nearest[c];
                newParent[u] = (u == 0) ? -1 :
                        (nearest[c] != -1 ? nearest[c] : parent[u]);
                nearest[c] = u;
                order[count++] = u;

                events[top++] = ~u; // Exit event for u.
                for (int child = head[u]; child != -1; child = next[child]) {
                    events[top++] = child;
                }
            } else {
                int u = ~event;
                nearest[label[u] - 'a'] = previous[u];
            }
        }

        int[] answer = new int[n];
        Arrays.fill(answer, 1);
        // Every new parent is an ancestor in the ORIGINAL tree.
        for (int i = count - 1; i > 0; i--) {
            int u = order[i];
            answer[newParent[u]] += answer[u];
        }
        return answer;
    }
}
