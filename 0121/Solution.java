class Solution{public int maxProfit(int[]p){int mn=Integer.MAX_VALUE,b=0;for(int x:p){mn=Math.min(mn,x);b=Math.max(b,x-mn);}return b;}}
