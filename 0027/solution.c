int removeElement(int*a,int n,int val){int w=0;for(int i=0;i<n;i++)if(a[i]!=val)a[w++]=a[i];return w;}
