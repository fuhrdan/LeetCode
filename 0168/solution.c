#include <stdlib.h>
char* convertToTitle(int n){char*b=malloc(16);int k=0;while(n){n--;b[k++]='A'+n%26;n/=26;}char*r=malloc(k+1);for(int i=0;i<k;i++)r[i]=b[k-1-i];r[k]=0;free(b);return r;}
