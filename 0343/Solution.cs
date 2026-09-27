public class Solution{public int IntegerBreak(int n){if(n<=3)return n-1;int r=1;while(n>4){r*=3;n-=3;}return r*n;}}
