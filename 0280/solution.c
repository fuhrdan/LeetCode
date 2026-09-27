void wiggleSort(int*a,int n){for(int i=1;i<n;i++)if((i&1&&a[i]<a[i-1])||(!(i&1)&&a[i]>a[i-1])){int t=a[i];a[i]=a[i-1];a[i-1]=t;}}
