class Solution{public int closestValue(TreeNode r,double t){int b=r.val;while(r!=null){if(Math.abs(r.val-t)<Math.abs(b-t))b=r.val;r=t<r.val?r.left:r.right;}return b;}}
