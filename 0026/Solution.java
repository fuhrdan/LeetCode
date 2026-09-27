class Solution{public int removeDuplicates(int[]a){if(a.length==0)return 0;int w=1;for(int i=1;i<a.length;i++)if(a[i]!=a[w-1])a[w++]=a[i];return w;}}
