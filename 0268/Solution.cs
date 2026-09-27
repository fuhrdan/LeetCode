public class Solution{public int MissingNumber(int[]a){int x=a.Length;for(int i=0;i<a.Length;i++)x^=i^a[i];return x;}}
