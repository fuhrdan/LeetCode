int trap(int*h,int n){int l=0,r=n-1,lm=0,rm=0,w=0;while(l<r){if(h[l]<h[r]){if(h[l]>=lm)lm=h[l];else w+=lm-h[l];l++;}else{if(h[r]>=rm)rm=h[r];else w+=rm-h[r];r--;}}return w;}
