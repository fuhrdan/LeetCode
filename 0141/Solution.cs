public class Solution{public bool HasCycle(ListNode h){var s=h;var f=h;while(f!=null&&f.next!=null){s=s.next;f=f.next.next;if(object.ReferenceEquals(s,f))return true;}return false;}}
