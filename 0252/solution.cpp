#include <vector>
#include <algorithm>
using namespace std;class Solution{public:bool canAttendMeetings(vector<vector<int>>&a){sort(a.begin(),a.end());for(int i=1;i<a.size();i++)if(a[i][0]<a[i-1][1])return false;return true;}};
