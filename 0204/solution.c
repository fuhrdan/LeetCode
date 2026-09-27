#include <stdlib.h>
int countPrimes(int n){if(n<=2)return 0;char*comp=calloc(n,1);int c=0;for(int i=2;i<n;i++){if(!comp[i]){c++;if((long long)i*i<n)for(int j=i*i;j<n;j+=i)comp[j]=1;}}free(comp);return c;}
