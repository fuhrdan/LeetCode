int maxProfit(int*p,int n){int r=0;for(int i=1;i<n;i++)if(p[i]>p[i-1])r+=p[i]-p[i-1];return r;}
