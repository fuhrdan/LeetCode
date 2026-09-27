public class Solution{public int ClimbStairs(int n){int a=1,b=1;while(n-->0){int t=a+b;a=b;b=t;}return a;}}
