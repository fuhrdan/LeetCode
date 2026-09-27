public class Solution{public int RemoveDuplicates(int[]a){int w=0;foreach(int x in a)if(w<2||x!=a[w-2])a[w++]=x;return w;}}
