class Solution{public int maxSubArray(int[]a){int c=a[0],b=a[0];for(int i=1;i<a.length;i++){c=Math.max(a[i],c+a[i]);b=Math.max(b,c);}return b;}}
