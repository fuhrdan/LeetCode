class Solution{public:int guessNumber(int n){long long l=1,r=n;while(l<=r){int m=l+(r-l)/2,g=guess(m);if(!g)return m;if(g<0)r=m-1;else l=m+1;}return-1;}};
