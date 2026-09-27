class Solution{public int countPrimes(int n){boolean[]c=new boolean[n];int r=0;for(int i=2;i<n;i++)if(!c[i]){r++;if((long)i*i<n)for(int j=i*i;j<n;j+=i)c[j]=true;}return r;}}
