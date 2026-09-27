#include <stdlib.h>
#include <stdbool.h>
typedef struct Trie{struct Trie*ch[26];bool end;}Trie;Trie* trieCreate(){return calloc(1,sizeof(Trie));}void trieInsert(Trie*t,char*w){for(int i=0;w[i];i++){int k=w[i]-'a';if(!t->ch[k])t->ch[k]=trieCreate();t=t->ch[k];}t->end=true;}bool trieSearch(Trie*t,char*w){for(int i=0;w[i];i++){t=t->ch[w[i]-'a'];if(!t)return false;}return t->end;}bool trieStartsWith(Trie*t,char*p){for(int i=0;p[i];i++){t=t->ch[p[i]-'a'];if(!t)return false;}return true;}void trieFree(Trie*t){if(!t)return;for(int i=0;i<26;i++)trieFree(t->ch[i]);free(t);}
