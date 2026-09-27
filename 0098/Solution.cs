public class Solution{bool F(TreeNode n,long lo,long hi)=>n==null||n.val>lo&&n.val<hi&&F(n.left,lo,n.val)&&F(n.right,n.val,hi);public bool IsValidBST(TreeNode r)=>F(r,long.MinValue,long.MaxValue);}
