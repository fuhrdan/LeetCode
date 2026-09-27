using System.Collections.Generic;public class Solution{public IList<int> GetRow(int n){int[]r=new int[n+1];r[0]=1;for(int i=1;i<=n;i++)for(int j=i;j>0;j--)r[j]+=r[j-1];return r;}}
