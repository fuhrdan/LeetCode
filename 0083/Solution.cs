public class Solution{public ListNode DeleteDuplicates(ListNode h){for(var p=h;p!=null&&p.next!=null;)if(p.val==p.next.val)p.next=p.next.next;else p=p.next;return h;}}
