using System;public class Solution{public int ClosestValue(TreeNode r,double t){int b=r.val;while(r!=null){if(Math.Abs(r.val-t)<Math.Abs(b-t))b=r.val;r=t<r.val?r.left:r.right;}return b;}}
