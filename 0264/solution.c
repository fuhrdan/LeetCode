#include <stdlib.h>
int nthUglyNumber(int n){long long*u=malloc(n*sizeof(long long));u[0]=1;int a=0,b=0,c=0;for(int i=1;i<n;i++){long long x=2*u[a],y=3*u[b],z=5*u[c],m=x<y?x:y;m=m<z?m:z;u[i]=m;if(m==x)a++;if(m==y)b++;if(m==z)c++;}int r=u[n-1];free(u);return r;}
