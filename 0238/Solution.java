class Solution{public int[] productExceptSelf(int[]a){int[]r=new int[a.length];int p=1;for(int i=0;i<a.length;i++){r[i]=p;p*=a[i];}p=1;for(int i=a.length-1;i>=0;i--){r[i]*=p;p*=a[i];}return r;}}
