class Solution{public int hIndex(int[]a){int n=a.length,l=0,r=n;while(l<r){int m=(l+r)/2;if(a[m]>=n-m)r=m;else l=m+1;}return n-l;}}
