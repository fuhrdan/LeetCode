public class Solution{public bool IsUgly(int n){if(n<=0)return false;foreach(int p in new[]{2,3,5})while(n%p==0)n/=p;return n==1;}}
