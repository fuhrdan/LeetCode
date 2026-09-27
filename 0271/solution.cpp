#include <string>
#include <vector>
using namespace std;class Codec{public:string encode(vector<string>&s){string r;for(auto&x:s)r+=to_string(x.size())+"#"+x;return r;}vector<string> decode(string s){vector<string>o;for(int i=0;i<s.size();){int j=i;while(s[j]!='#')j++;int n=stoi(s.substr(i,j-i));o.push_back(s.substr(j+1,n));i=j+1+n;}return o;}};
