class Solution{public int countNumbersWithUniqueDigits(int n){if(n==0)return 1;n=Math.min(n,10);int r=10,cur=9,a=9;for(int l=2;l<=n;l++){cur*=a--;r+=cur;}return r;}}
