class Solution{public int minCost(int[][]c){int a=0,b=0,d=0;for(int[]x:c){int na=x[0]+Math.min(b,d),nb=x[1]+Math.min(a,d),nd=x[2]+Math.min(a,b);a=na;b=nb;d=nd;}return Math.min(a,Math.min(b,d));}}
