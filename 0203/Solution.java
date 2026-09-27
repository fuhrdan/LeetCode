class Solution{public ListNode removeElements(ListNode h,int val){ListNode d=new ListNode(0,h),p=d;while(p.next!=null){if(p.next.val==val)p.next=p.next.next;else p=p.next;}return d.next;}}
