int missingNumber(int*a,int n){int x=n;for(int i=0;i<n;i++)x^=i^a[i];return x;}
