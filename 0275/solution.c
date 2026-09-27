int hIndex(int*a,int n){int l=0,r=n;while(l<r){int m=(l+r)/2;if(a[m]>=n-m)r=m;else l=m+1;}return n-l;}
