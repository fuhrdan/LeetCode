class Solution{public:int firstBadVersion(int n){long long l=1,r=n;while(l<r){long long m=l+(r-l)/2;if(isBadVersion(m))r=m;else l=m+1;}return l;}};
