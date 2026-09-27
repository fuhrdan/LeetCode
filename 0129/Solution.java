class Solution{int f(TreeNode n,int v){if(n==null)return 0;v=v*10+n.val;if(n.left==null&&n.right==null)return v;return f(n.left,v)+f(n.right,v);}public int sumNumbers(TreeNode r){return f(r,0);}}
