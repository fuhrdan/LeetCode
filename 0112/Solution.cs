public class Solution{public bool HasPathSum(TreeNode r,int t){if(r==null)return false;if(r.left==null&&r.right==null)return r.val==t;return HasPathSum(r.left,t-r.val)||HasPathSum(r.right,t-r.val);}}
