public class Solution{int F(TreeNode n,int v){if(n==null)return 0;v=v*10+n.val;if(n.left==null&&n.right==null)return v;return F(n.left,v)+F(n.right,v);}public int SumNumbers(TreeNode r)=>F(r,0);}
