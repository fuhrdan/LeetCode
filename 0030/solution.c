#include <stdlib.h>
#include <string.h>
static int findWord(char**w,int k,char*s,int len){for(int i=0;i<k;i++)if(strncmp(w[i],s,len)==0&&w[i][len]==0)return i;return -1;}
int* findSubstring(char*s,char**words,int wordsSize,int*returnSize){int n=strlen(s),wl=strlen(words[0]),total=wl*wordsSize,cap=16,cnt=0;int*out=malloc(cap*sizeof(int));int*need=calloc(wordsSize,sizeof(int));for(int i=0;i<wordsSize;i++){int id=findWord(words,i,words[i],wl);need[id<0?i:id]++;}for(int st=0;st+total<=n;st++){int*used=calloc(wordsSize,sizeof(int)),ok=1;for(int j=0;j<wordsSize;j++){int id=findWord(words,wordsSize,s+st+j*wl,wl);if(id<0||++used[id]>need[id]){ok=0;break;}}free(used);if(ok){if(cnt==cap){cap*=2;out=realloc(out,cap*sizeof(int));}out[cnt++]=st;}}free(need);*returnSize=cnt;return out;}
