#include <string>
#include <vector>
using namespace std;class Solution{string lo,hi;int c=0;vector<pair<char,char>>p{{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};void f(string&s,int l,int r){if(l>r){if((s.size()>lo.size()||s>=lo)&&(s.size()<hi.size()||s<=hi))c++;return;}for(auto[a,b]:p){if(l==0&&s.size()>1&&a=='0')continue;if(l==r&&a!=b)continue;s[l]=a;s[r]=b;f(s,l+1,r-1);}}public:int strobogrammaticInRange(string low,string high){lo=low;hi=high;for(int n=lo.size();n<=hi.size();n++){string s(n,' ');f(s,0,n-1);}return c;}};
