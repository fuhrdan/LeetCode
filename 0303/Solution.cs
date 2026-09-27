public class NumArray{long[]p;public NumArray(int[]a){p=new long[a.Length+1];for(int i=0;i<a.Length;i++)p[i+1]=p[i]+a[i];}public int SumRange(int l,int r)=>(int)(p[r+1]-p[l]);}
