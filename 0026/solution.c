int removeDuplicates(int* a,int n){if(!n)return 0;int w=1;for(int i=1;i<n;i++)if(a[i]!=a[w-1])a[w++]=a[i];return w;}
