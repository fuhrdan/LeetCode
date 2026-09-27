class Solution{public int uniquePathsWithObstacles(int[][]g){int n=g[0].length;int[]d=new int[n];d[0]=1;for(int[]r:g)for(int j=0;j<n;j++)if(r[j]==1)d[j]=0;else if(j>0)d[j]+=d[j-1];return d[n-1];}}
