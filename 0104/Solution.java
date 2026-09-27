class Solution{public int maxDepth(TreeNode r){return r==null?0:1+Math.max(maxDepth(r.left),maxDepth(r.right));}}
