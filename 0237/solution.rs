impl Solution{pub fn delete_node(node:&mut Box<ListNode>){let mut next=node.next.take().unwrap();node.val=next.val;node.next=next.next.take();}}
