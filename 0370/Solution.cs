public class Solution{public int[] GetModifiedArray(int n,int[][]u){int[]r=new int[n];foreach(var x in u){r[x[0]]+=x[2];if(x[1]+1<n)r[x[1]+1]-=x[2];}for(int i=1;i<n;i++)r[i]+=r[i-1];return r;}}
