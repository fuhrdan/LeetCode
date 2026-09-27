import java.util.*;class Solution{public int hIndex(int[]a){Arrays.sort(a);for(int i=0;i<a.length;i++)if(a[i]>=a.length-i)return a.length-i;return 0;}}
