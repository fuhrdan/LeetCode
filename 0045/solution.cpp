#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int jump(vector<int>&a){int j=0,e=0,f=0;for(int i=0;i+1<a.size();i++){f=max(f,i+a[i]);if(i==e){j++;e=f;}}return j;}};
