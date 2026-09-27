class Solution{public int findPeakElement(int[]a){int l=0,r=a.length-1;while(l<r){int m=(l+r)/2;if(a[m]<a[m+1])l=m+1;else r=m;}return l;}}
