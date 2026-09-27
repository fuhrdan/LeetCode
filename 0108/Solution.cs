public class Solution{TreeNode F(int[]a,int l,int r){if(l>r)return null;int m=(l+r)/2;return new TreeNode(a[m],F(a,l,m-1),F(a,m+1,r));}public TreeNode SortedArrayToBST(int[]a)=>F(a,0,a.Length-1);}
