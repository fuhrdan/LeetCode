public class Solution : VersionControl{public int FirstBadVersion(int n){long l=1,r=n;while(l<r){long m=l+(r-l)/2;if(IsBadVersion((int)m))r=m;else l=m+1;}return(int)l;}}
