using System;public class Solution{public int NumSquares(int n){int[]d=new int[n+1];for(int i=1;i<=n;i++){d[i]=i;for(int j=1;j*j<=i;j++)d[i]=Math.Min(d[i],d[i-j*j]+1);}return d[n];}}
