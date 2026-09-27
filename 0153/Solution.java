class Solution{public int findMin(int[]a){int l=0,r=a.length-1;while(l<r){int m=(l+r)/2;if(a[m]>a[r])l=m+1;else r=m;}return a[l];}}
