class Solution{public int jump(int[]a){int j=0,e=0,f=0;for(int i=0;i<a.length-1;i++){f=Math.max(f,i+a[i]);if(i==e){j++;e=f;}}return j;}}
