class Solution{public:int countDigitOne(int n){long long r=0;for(long long f=1;f<=n;f*=10){long long lo=n%f,c=n/f%10,hi=n/(f*10);r+=c==0?hi*f:c==1?hi*f+lo+1:(hi+1)*f;if(f>n/10)break;}return r;}};
