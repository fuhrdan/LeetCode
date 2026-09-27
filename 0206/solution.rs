impl Solution{pub fn reverse_list(mut head:Option<Box<ListNode>>)->Option<Box<ListNode>>{let mut prev=None;while let Some(mut n)=head{head=n.next.take();n.next=prev;prev=Some(n);}prev}}
