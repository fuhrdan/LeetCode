using System;public class Solution{public int HIndex(int[]a){Array.Sort(a);for(int i=0;i<a.Length;i++)if(a[i]>=a.Length-i)return a.Length-i;return 0;}}
