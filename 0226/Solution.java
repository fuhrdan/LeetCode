class Solution{public TreeNode invertTree(TreeNode r){if(r==null)return null;TreeNode t=r.left;r.left=invertTree(r.right);r.right=invertTree(t);return r;}}
