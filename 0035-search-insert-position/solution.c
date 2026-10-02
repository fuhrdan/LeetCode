int searchInsert(int*a,int n,int t){int l=0,r=n;while(l<r){int m=(l+r)/2;if(a[m]<t)l=m+1;else r=m;}return l;}
