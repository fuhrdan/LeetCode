class Solution {
    public double findMedianSortedArrays(int[] a,int[] b){
        if(a.length>b.length) return findMedianSortedArrays(b,a);
        int m=a.length,n=b.length,lo=0,hi=m,total=m+n;
        while(lo<=hi){
            int i=(lo+hi)/2,j=(total+1)/2-i;
            int al=i==0?Integer.MIN_VALUE:a[i-1], ar=i==m?Integer.MAX_VALUE:a[i];
            int bl=j==0?Integer.MIN_VALUE:b[j-1], br=j==n?Integer.MAX_VALUE:b[j];
            if(al<=br&&bl<=ar){ int left=Math.max(al,bl); if((total&1)==1)return left; return ((double)left+Math.min(ar,br))/2.0; }
            if(al>br) hi=i-1; else lo=i+1;
        }
        return 0;
    }
}
