public class Solution{public ListNode RemoveElements(ListNode h,int val){var d=new ListNode(0,h);var p=d;while(p.next!=null){if(p.next.val==val)p.next=p.next.next;else p=p.next;}return d.next;}}
