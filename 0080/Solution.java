class Solution{public int removeDuplicates(int[]a){int w=0;for(int x:a)if(w<2||x!=a[w-2])a[w++]=x;return w;}}
