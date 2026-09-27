#include <array>
#include <string>
using namespace std;class WordDictionary{struct N{array<N*,26>c{};bool end=false;};N*r=new N;bool f(N*p,const string&s,int i){if(!p)return false;if(i==s.size())return p->end;if(s[i]=='.'){for(auto x:p->c)if(f(x,s,i+1))return true;return false;}return f(p->c[s[i]-'a'],s,i+1);}public:WordDictionary(){}void addWord(string s){N*p=r;for(char x:s){int k=x-'a';if(!p->c[k])p->c[k]=new N;p=p->c[k];}p->end=true;}bool search(string s){return f(r,s,0);}};
