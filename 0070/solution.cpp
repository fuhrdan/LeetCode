class Solution{public:int climbStairs(int n){int a=1,b=1;while(n--){int t=a+b;a=b;b=t;}return a;}};
