class Solution{public boolean canJump(int[]a){int f=0;for(int i=0;i<a.length;i++){if(i>f)return false;f=Math.max(f,i+a[i]);}return true;}}
