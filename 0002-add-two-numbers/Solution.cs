public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        var dummy=new ListNode(0); var tail=dummy; int carry=0;
        while(l1!=null||l2!=null||carry!=0){
            int sum=carry+(l1==null?0:l1.val)+(l2==null?0:l2.val);
            tail.next=new ListNode(sum%10); tail=tail.next; carry=sum/10;
            if(l1!=null) l1=l1.next; if(l2!=null) l2=l2.next;
        }
        return dummy.next;
    }
}
