public class Solution{public ListNode ReverseList(ListNode h){ListNode p=null;while(h!=null){var n=h.next;h.next=p;p=h;h=n;}return p;}}
