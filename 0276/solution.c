int numWays(int n,int k){if(n==0)return 0;if(n==1)return k;long same=k,diff=(long)k*(k-1);for(int i=3;i<=n;i++){long ns=diff,nd=(same+diff)*(k-1);same=ns;diff=nd;}return same+diff;}
