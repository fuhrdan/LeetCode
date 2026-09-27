#include <algorithm>
using namespace std;class Solution{public:int computeArea(int ax1,int ay1,int ax2,int ay2,int bx1,int by1,int bx2,int by2){long long a=1LL*(ax2-ax1)*(ay2-ay1)+1LL*(bx2-bx1)*(by2-by1);int w=min(ax2,bx2)-max(ax1,bx1),h=min(ay2,by2)-max(ay1,by1);if(w>0&&h>0)a-=1LL*w*h;return a;}};
