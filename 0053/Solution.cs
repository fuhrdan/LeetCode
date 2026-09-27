using System;public class Solution{public int MaxSubArray(int[]a){int c=a[0],b=a[0];for(int i=1;i<a.Length;i++){c=Math.Max(a[i],c+a[i]);b=Math.Max(b,c);}return b;}}
