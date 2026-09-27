class Solution{public int integerReplacement(int n){long x=n;int c=0;while(x!=1){if((x&1)==0)x>>=1;else if(x==3||(x&3)==1)x--;else x++;c++;}return c;}}
