public class Solution{public ListNode GetIntersectionNode(ListNode a,ListNode b){var x=a;var y=b;while(!object.ReferenceEquals(x,y)){x=x==null?b:x.next;y=y==null?a:y.next;}return x;}}
