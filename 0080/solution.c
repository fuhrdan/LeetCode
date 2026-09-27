int removeDuplicates(int*a,int n){int w=0;for(int i=0;i<n;i++)if(w<2||a[i]!=a[w-2])a[w++]=a[i];return w;}
