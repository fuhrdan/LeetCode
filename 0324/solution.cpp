#include <vector>
#include <algorithm>
using namespace std;class Solution{public:void wiggleSort(vector<int>&a){vector<int>b=a;sort(b.begin(),b.end());int l=(a.size()-1)/2,r=a.size()-1;for(int i=0;i<a.size();i++)a[i]=i%2?b[r--]:b[l--];}};
