public class Solution extends VersionControl{public int firstBadVersion(int n){long l=1,r=n;while(l<r){long m=l+(r-l)/2;if(isBadVersion((int)m))r=m;else l=m+1;}return(int)l;}}
