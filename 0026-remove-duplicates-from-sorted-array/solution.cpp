#include <vector>
using namespace std; class Solution{public:int removeDuplicates(vector<int>&a){if(a.empty())return 0;int w=1;for(int i=1;i<a.size();i++)if(a[i]!=a[w-1])a[w++]=a[i];return w;}};
