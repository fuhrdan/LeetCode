public class Solution{public TreeNode InvertTree(TreeNode r){if(r==null)return null;var t=r.left;r.left=InvertTree(r.right);r.right=InvertTree(t);return r;}}
