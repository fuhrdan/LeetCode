using System;public class Solution{public int MySqrt(int x){int l=0,r=Math.Min(x,46340);while(l<=r){int m=l+(r-l)/2;if(m<=x/m)l=m+1;else r=m-1;}return r;}}
