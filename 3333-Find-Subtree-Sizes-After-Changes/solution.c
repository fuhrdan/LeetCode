/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSubtreeSizes(int* parent, int parentSize, char* s, int* returnSize) {
    const int n = parentSize;
    *returnSize = 0;
    if (n <= 0) return NULL;

    int *head = malloc((size_t)n * sizeof(int));
    int *next = malloc((size_t)n * sizeof(int));
    int *previous = malloc((size_t)n * sizeof(int));
    int *newParent = malloc((size_t)n * sizeof(int));
    int *order = malloc((size_t)n * sizeof(int));
    int *events = malloc((size_t)2 * n * sizeof(int));
    int *answer = malloc((size_t)n * sizeof(int));

    if (!head || !next || !previous || !newParent ||
        !order || !events || !answer) {
        free(head); free(next); free(previous); free(newParent);
        free(order); free(events); free(answer);
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        head[i] = -1;
        answer[i] = 1;
    }
    for (int node = 1; node < n; node++) {
        int p = parent[node];
        next[node] = head[p];
        head[p] = node;
    }

    int nearest[26];
    for (int c = 0; c < 26; c++) nearest[c] = -1;

    int top = 0, count = 0;
    events[top++] = 0;
    while (top > 0) {
        int event = events[--top];
        if (event >= 0) {
            int u = event;
            int c = s[u] - 'a';
            previous[u] = nearest[c];
            newParent[u] = (u == 0) ? -1 :
                           (nearest[c] != -1 ? nearest[c] : parent[u]);
            nearest[c] = u;
            order[count++] = u;

            events[top++] = ~u;
            for (int child = head[u]; child != -1; child = next[child]) {
                events[top++] = child;
            }
        } else {
            int u = ~event;
            nearest[s[u] - 'a'] = previous[u];
        }
    }

    for (int i = count - 1; i >= 1; i--) {
        int u = order[i];
        answer[newParent[u]] += answer[u];
    }

    free(head); free(next); free(previous); free(newParent);
    free(order); free(events);
    *returnSize = n;
    return answer;
}