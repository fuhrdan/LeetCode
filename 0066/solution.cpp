#include <vector>
using namespace std;class Solution{public:vector<int> plusOne(vector<int>&d){for(int i=d.size()-1;i>=0;i--){if(d[i]<9){d[i]++;return d;}d[i]=0;}d.insert(d.begin(),1);return d;}};
