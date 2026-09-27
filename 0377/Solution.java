class Solution{public int combinationSum4(int[]a,int target){long[]d=new long[target+1];d[0]=1;for(int t=1;t<=target;t++)for(int x:a)if(x<=t)d[t]+=d[t-x];return(int)d[target];}}
