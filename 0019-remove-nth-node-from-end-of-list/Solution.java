class Solution{public ListNode removeNthFromEnd(ListNode h,int n){ListNode d=new ListNode(0,h),f=d,s=d;while(n-->0)f=f.next;while(f.next!=null){f=f.next;s=s.next;}s.next=s.next.next;return d.next;}}
