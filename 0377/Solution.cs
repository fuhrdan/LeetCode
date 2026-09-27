public class Solution{public int CombinationSum4(int[]a,int target){ulong[]d=new ulong[target+1];d[0]=1;for(int t=1;t<=target;t++)foreach(int x in a)if(x<=t)d[t]+=d[t-x];return(int)d[target];}}
