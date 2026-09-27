class Solution{public int trap(int[]h){int l=0,r=h.length-1,lm=0,rm=0,w=0;while(l<r){if(h[l]<h[r]){lm=Math.max(lm,h[l]);w+=lm-h[l++];}else{rm=Math.max(rm,h[r]);w+=rm-h[r--];}}return w;}}
