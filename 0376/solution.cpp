#include <vector>
using namespace std;class Solution{public:int wiggleMaxLength(vector<int>&a){if(a.empty())return 0;int up=1,down=1;for(int i=1;i<a.size();i++){if(a[i]>a[i-1])up=down+1;else if(a[i]<a[i-1])down=up+1;}return max(up,down);}};
