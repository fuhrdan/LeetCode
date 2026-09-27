#include <string>
#include <vector>
#include <algorithm>
using namespace std;class Solution{public:string shortestPalindrome(string s){string r=s;reverse(r.begin(),r.end());string t=s+"#"+r;vector<int>p(t.size());for(int i=1;i<t.size();i++){int j=p[i-1];while(j&&t[i]!=t[j])j=p[j-1];if(t[i]==t[j])j++;p[i]=j;}return r.substr(0,s.size()-p.back())+s;}};
