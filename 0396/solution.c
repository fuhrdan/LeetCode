long long maxRotateFunction(int*a,int n){long long sum=0,f=0;for(int i=0;i<n;i++){sum+=a[i];f+=(long long)i*a[i];}long long b=f;for(int k=1;k<n;k++){f+=sum-(long long)n*a[n-k];if(f>b)b=f;}return b;}
