#include <vector>
using namespace std;class Solution{public:int minPatches(vector<int>&a,int n){long long miss=1;int i=0,c=0;while(miss<=n){if(i<a.size()&&a[i]<=miss)miss+=a[i++];else miss+=miss,c++;}return c;}};
