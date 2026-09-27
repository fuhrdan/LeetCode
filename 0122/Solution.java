class Solution{public int maxProfit(int[]p){int r=0;for(int i=1;i<p.length;i++)if(p[i]>p[i-1])r+=p[i]-p[i-1];return r;}}
