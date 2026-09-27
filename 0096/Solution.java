class Solution{public int numTrees(int n){int[]d=new int[n+1];d[0]=1;if(n>0)d[1]=1;for(int x=2;x<=n;x++)for(int r=1;r<=x;r++)d[x]+=d[r-1]*d[x-r];return d[n];}}
