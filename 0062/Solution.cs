public class Solution{public int UniquePaths(int m,int n){int[]d=new int[n];for(int j=0;j<n;j++)d[j]=1;for(int i=1;i<m;i++)for(int j=1;j<n;j++)d[j]+=d[j-1];return d[n-1];}}
