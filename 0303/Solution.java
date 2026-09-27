class NumArray{long[]p;public NumArray(int[]a){p=new long[a.length+1];for(int i=0;i<a.length;i++)p[i+1]=p[i]+a[i];}public int sumRange(int l,int r){return(int)(p[r+1]-p[l]);}}
