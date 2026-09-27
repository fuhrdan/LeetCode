int minCost(int**c,int n,int*cols){int a=0,b=0,d=0;for(int i=0;i<n;i++){int na=c[i][0]+(b<d?b:d),nb=c[i][1]+(a<d?a:d),nd=c[i][2]+(a<b?a:b);a=na;b=nb;d=nd;}int r=a<b?a:b;return r<d?r:d;}
