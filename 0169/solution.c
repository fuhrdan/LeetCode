int majorityElement(int*a,int n){int c=0,x=0;for(int i=0;i<n;i++){if(!c)x=a[i];c+=a[i]==x?1:-1;}return x;}
