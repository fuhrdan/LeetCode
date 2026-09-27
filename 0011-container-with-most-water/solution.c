int maxArea(int* h,int n){int l=0,r=n-1,b=0;while(l<r){int x=h[l]<h[r]?h[l]:h[r],a=x*(r-l);if(a>b)b=a;if(h[l]<h[r])l++;else r--;}return b;}
