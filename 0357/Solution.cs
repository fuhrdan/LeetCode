using System;public class Solution{public int CountNumbersWithUniqueDigits(int n){if(n==0)return 1;n=Math.Min(n,10);int r=10,cur=9,a=9;for(int l=2;l<=n;l++){cur*=a--;r+=cur;}return r;}}
