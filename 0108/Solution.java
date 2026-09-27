class Solution{TreeNode f(int[]a,int l,int r){if(l>r)return null;int m=(l+r)/2;return new TreeNode(a[m],f(a,l,m-1),f(a,m+1,r));}public TreeNode sortedArrayToBST(int[]a){return f(a,0,a.length-1);}}
