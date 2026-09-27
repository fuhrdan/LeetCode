class Solution{public ListNode reverseList(ListNode h){ListNode p=null;while(h!=null){ListNode n=h.next;h.next=p;p=h;h=n;}return p;}}
