class Solution{public int missingNumber(int[]a){int x=a.length;for(int i=0;i<a.length;i++)x^=i^a[i];return x;}}
