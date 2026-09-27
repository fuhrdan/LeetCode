class Solution{public:int numWays(int n,int k){if(!n)return 0;if(n==1)return k;long long s=k,d=1LL*k*(k-1);for(int i=3;i<=n;i++){long long ns=d,nd=(s+d)*(k-1);s=ns;d=nd;}return s+d;}};
