class Solution{public:int countNumbersWithUniqueDigits(int n){if(!n)return 1;n=min(n,10);int r=10,cur=9,a=9;for(int l=2;l<=n;l++){cur*=a--;r+=cur;}return r;}};
