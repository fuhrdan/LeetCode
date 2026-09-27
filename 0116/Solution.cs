public class Solution{public Node Connect(Node r){for(Node l=r;l!=null&&l.left!=null;l=l.left)for(Node p=l;p!=null;p=p.next){p.left.next=p.right;if(p.next!=null)p.right.next=p.next.left;}return r;}}
