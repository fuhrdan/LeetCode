using System;public class Solution{public int Jump(int[]a){int j=0,e=0,f=0;for(int i=0;i<a.Length-1;i++){f=Math.Max(f,i+a[i]);if(i==e){j++;e=f;}}return j;}}
