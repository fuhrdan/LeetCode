impl Solution{pub fn is_palindrome(head:Option<Box<ListNode>>)->bool{let mut v=vec![];let mut p=head.as_ref();while let Some(n)=p{v.push(n.val);p=n.next.as_ref();}v.iter().eq(v.iter().rev())}}
