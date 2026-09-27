public class Solution{public int NumWays(int n,int k){if(n==0)return 0;if(n==1)return k;long s=k,d=(long)k*(k-1);for(int i=3;i<=n;i++){long ns=d,nd=(s+d)*(k-1);s=ns;d=nd;}return(int)(s+d);}}
