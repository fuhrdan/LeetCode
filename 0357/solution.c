int countNumbersWithUniqueDigits(int n){if(n==0)return 1;if(n>10)n=10;int r=10,cur=9,avail=9;for(int len=2;len<=n;len++){cur*=avail--;r+=cur;}return r;}
