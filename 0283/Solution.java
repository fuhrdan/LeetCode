class Solution{public void moveZeroes(int[]a){int j=0;for(int x:a)if(x!=0)a[j++]=x;while(j<a.length)a[j++]=0;}}
