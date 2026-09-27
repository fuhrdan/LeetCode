#include <string>
#include <vector>
#include <unordered_map>
using namespace std;class ValidWordAbbr{unordered_map<string,string>m;string a(string s){return s.size()<=2?s:s[0]+to_string(s.size()-2)+s.back();}public:ValidWordAbbr(vector<string>&d){for(auto&s:d){string k=a(s);if(!m.count(k))m[k]=s;else if(m[k]!=s)m[k]="#";}}bool isUnique(string w){string k=a(w);return !m.count(k)||m[k]==w;}};
