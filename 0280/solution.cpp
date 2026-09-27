#include <vector>
using namespace std;class Solution{public:void wiggleSort(vector<int>&a){for(int i=1;i<a.size();i++)if((i&1&&a[i]<a[i-1])||(!(i&1)&&a[i]>a[i-1]))swap(a[i],a[i-1]);}};
