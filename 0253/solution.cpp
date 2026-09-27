#include <vector>
#include <algorithm>
using namespace std;class Solution{public:int minMeetingRooms(vector<vector<int>>&a){vector<int>s,e;for(auto&x:a){s.push_back(x[0]);e.push_back(x[1]);}sort(s.begin(),s.end());sort(e.begin(),e.end());int i=0,j=0,c=0,b=0;while(i<s.size()){if(s[i]<e[j]){b=max(b,++c);i++;}else{c--;j++;}}return b;}};
