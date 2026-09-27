#include <vector>
using namespace std;class Solution{public:vector<int> twoSum(vector<int>&a,int t){int l=0,r=a.size()-1;while(l<r){int s=a[l]+a[r];if(s==t)return{l+1,r+1};if(s<t)l++;else r--;}return{};}};
