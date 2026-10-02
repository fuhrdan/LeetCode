public class Solution{public int RemoveElement(int[]a,int v){int w=0;foreach(int x in a)if(x!=v)a[w++]=x;return w;}}
