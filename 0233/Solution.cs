public class Solution{public int CountDigitOne(int n){long r=0;for(long f=1;f<=n;f*=10){long lo=n%f,c=n/f%10,hi=n/(f*10);r+=c==0?hi*f:c==1?hi*f+lo+1:(hi+1)*f;if(f>n/10)break;}return(int)r;}}
