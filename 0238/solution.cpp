#include <vector>
using namespace std;class Solution{public:vector<int> productExceptSelf(vector<int>&a){vector<int>r(a.size());int p=1;for(int i=0;i<a.size();i++){r[i]=p;p*=a[i];}p=1;for(int i=a.size()-1;i>=0;i--){r[i]*=p;p*=a[i];}return r;}};
