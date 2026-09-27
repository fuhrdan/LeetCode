#include <vector>
#include <string>
using namespace std;class Solution{vector<string>o;vector<pair<char,char>>p{{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};void f(string&s,int l,int r){if(l>r){o.push_back(s);return;}for(auto[a,b]:p){if(l==0&&r>0&&a=='0')continue;if(l==r&&a!=b)continue;s[l]=a;s[r]=b;f(s,l+1,r-1);}}public:vector<string> findStrobogrammatic(int n){string s(n,' ');f(s,0,n-1);return o;}};
