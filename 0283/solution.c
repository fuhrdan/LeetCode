void moveZeroes(int*a,int n){int j=0;for(int i=0;i<n;i++)if(a[i])a[j++]=a[i];while(j<n)a[j++]=0;}
