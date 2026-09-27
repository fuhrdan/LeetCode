public class Solution{TreeNode p;void F(TreeNode n){if(n==null)return;F(n.right);F(n.left);n.right=p;n.left=null;p=n;}public void Flatten(TreeNode r){F(r);}}
