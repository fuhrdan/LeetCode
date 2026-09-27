#include <array>
#include <string>
using namespace std;class Trie{struct N{array<N*,26>c{};bool end=false;};N*r=new N;public:Trie(){}void insert(string w){N*p=r;for(char x:w){int k=x-'a';if(!p->c[k])p->c[k]=new N;p=p->c[k];}p->end=true;}bool search(string w){N*p=r;for(char x:w){p=p->c[x-'a'];if(!p)return false;}return p->end;}bool startsWith(string pfx){N*p=r;for(char x:pfx){p=p->c[x-'a'];if(!p)return false;}return true;}};
