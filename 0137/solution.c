int singleNumber(int*a,int n){int ones=0,twos=0;for(int i=0;i<n;i++){ones=(ones^a[i])&~twos;twos=(twos^a[i])&~ones;}return ones;}
