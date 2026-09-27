using System;public class Solution{public int MaxDepth(TreeNode r)=>r==null?0:1+Math.Max(MaxDepth(r.left),MaxDepth(r.right));}
