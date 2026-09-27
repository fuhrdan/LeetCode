public class Solution{public int MaxProfit(int[]p){int r=0;for(int i=1;i<p.Length;i++)if(p[i]>p[i-1])r+=p[i]-p[i-1];return r;}}
