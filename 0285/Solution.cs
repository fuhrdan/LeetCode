public class Solution{public TreeNode InorderSuccessor(TreeNode r,TreeNode p){TreeNode s=null;while(r!=null){if(p.val<r.val){s=r;r=r.left;}else r=r.right;}return s;}}
