#include <vector>
using namespace std;class Solution{public:void moveZeroes(vector<int>&a){int j=0;for(int x:a)if(x)a[j++]=x;while(j<a.size())a[j++]=0;}};
