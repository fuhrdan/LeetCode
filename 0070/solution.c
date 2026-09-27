int climbStairs(int n){int a=1,b=1;for(int i=0;i<n;i++){int t=a+b;a=b;b=t;}return a;}
