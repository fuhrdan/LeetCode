class Solution{public boolean hasPathSum(TreeNode r,int t){if(r==null)return false;if(r.left==null&&r.right==null)return r.val==t;return hasPathSum(r.left,t-r.val)||hasPathSum(r.right,t-r.val);}}
