#include <vector>
using namespace std;class ZigzagIterator{vector<int>a,b;int i=0,j=0,t=0;public:ZigzagIterator(vector<int>&x,vector<int>&y):a(x),b(y){}int next(){if((t==0&&i<a.size())||j==b.size()){t=1;return a[i++];}t=0;return b[j++];}bool hasNext(){return i<a.size()||j<b.size();}};
