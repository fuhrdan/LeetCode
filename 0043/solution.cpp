#include <string>
#include <vector>
using namespace std;class Solution{public:string multiply(string a,string b){if(a=="0"||b=="0")return"0";vector<int>d(a.size()+b.size());for(int i=a.size()-1;i>=0;i--)for(int j=b.size()-1;j>=0;j--){int p=(a[i]-'0')*(b[j]-'0')+d[i+j+1];d[i+j+1]=p%10;d[i+j]+=p/10;}string s;int i=d[0]==0;for(;i<d.size();i++)s+=char('0'+d[i]);return s;}};
