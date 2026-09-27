class Solution{public int maxArea(int[]h){int l=0,r=h.length-1,b=0;while(l<r){b=Math.max(b,Math.min(h[l],h[r])*(r-l));if(h[l]<h[r])l++;else r--;}return b;}}
