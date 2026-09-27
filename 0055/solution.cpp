#include <vector>
#include <algorithm>
using namespace std;class Solution{public:bool canJump(vector<int>&a){int f=0;for(int i=0;i<a.size();i++){if(i>f)return false;f=max(f,i+a[i]);}return true;}};
