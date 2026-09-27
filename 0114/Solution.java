class Solution{TreeNode p;void f(TreeNode n){if(n==null)return;f(n.right);f(n.left);n.right=p;n.left=null;p=n;}public void flatten(TreeNode r){f(r);}}
