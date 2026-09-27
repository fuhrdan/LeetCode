#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;class Solution{public:int longestConsecutive(vector<int>&a){unordered_set<int>s(a.begin(),a.end());int b=0;for(int x:s)if(!s.count(x-1)){int y=x;while(s.count(y))y++;b=max(b,y-x);}return b;}};
