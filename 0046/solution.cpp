#include <vector>
using namespace std;class Solution{vector<vector<int>>o;void f(vector<int>&a,int p){if(p==a.size()){o.push_back(a);return;}for(int i=p;i<a.size();i++){swap(a[p],a[i]);f(a,p+1);swap(a[p],a[i]);}}public:vector<vector<int>> permute(vector<int>&a){f(a,0);return o;}};
