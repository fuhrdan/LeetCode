#include <vector>
using namespace std;class Vector2D{vector<vector<int>>&v;int r=0,c=0;void a(){while(r<v.size()&&c==v[r].size()){r++;c=0;}}public:Vector2D(vector<vector<int>>&x):v(x){}int next(){a();return v[r][c++];}bool hasNext(){a();return r<v.size();}};
