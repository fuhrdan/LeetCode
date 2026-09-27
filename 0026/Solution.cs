public class Solution{public int RemoveDuplicates(int[]a){if(a.Length==0)return 0;int w=1;for(int i=1;i<a.Length;i++)if(a[i]!=a[w-1])a[w++]=a[i];return w;}}
