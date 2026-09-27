using System;
public class Solution {
    public double FindMedianSortedArrays(int[] a,int[] b){
        if(a.Length>b.Length) return FindMedianSortedArrays(b,a);
        int m=a.Length,n=b.Length,lo=0,hi=m,total=m+n;
        while(lo<=hi){
            int i=(lo+hi)/2,j=(total+1)/2-i;
            int al=i==0?int.MinValue:a[i-1], ar=i==m?int.MaxValue:a[i];
            int bl=j==0?int.MinValue:b[j-1], br=j==n?int.MaxValue:b[j];
            if(al<=br&&bl<=ar){ int left=Math.Max(al,bl); if((total&1)==1)return left; return ((double)left+Math.Min(ar,br))/2.0; }
            if(al>br) hi=i-1; else lo=i+1;
        }
        return 0;
    }
}
