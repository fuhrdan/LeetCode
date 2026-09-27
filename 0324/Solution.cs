using System;public class Solution{public void WiggleSort(int[]a){int[]b=(int[])a.Clone();Array.Sort(b);int l=(a.Length-1)/2,r=a.Length-1;for(int i=0;i<a.Length;i++)a[i]=i%2==0?b[l--]:b[r--];}}
