#include <string>
#include <unordered_map>
using namespace std;class Solution{string a,b;unordered_map<long long,bool>m;bool f(int i,int j,int n){long long key=((long long)i<<40)|((long long)j<<20)|n;if(m.count(key))return m[key];int c[26]{};for(int k=0;k<n;k++){c[a[i+k]-'a']++;c[b[j+k]-'a']--;}for(int x:c)if(x)return m[key]=false;if(a.compare(i,n,b,j,n)==0)return m[key]=true;for(int k=1;k<n;k++)if((f(i,j,k)&&f(i+k,j+k,n-k))||(f(i,j+n-k,k)&&f(i+k,j,n-k)))return m[key]=true;return m[key]=false;}public:bool isScramble(string s1,string s2){a=s1;b=s2;return a.size()==b.size()&&f(0,0,a.size());}};
