public class Solution{public int SearchInsert(int[]a,int t){int l=0,r=a.Length;while(l<r){int m=(l+r)/2;if(a[m]<t)l=m+1;else r=m;}return l;}}
