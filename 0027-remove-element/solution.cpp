#include <vector>
using namespace std;class Solution{public:int removeElement(vector<int>&a,int v){int w=0;for(int x:a)if(x!=v)a[w++]=x;return w;}};
