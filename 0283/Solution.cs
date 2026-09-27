public class Solution{public void MoveZeroes(int[]a){int j=0;foreach(int x in a)if(x!=0)a[j++]=x;while(j<a.Length)a[j++]=0;}}
