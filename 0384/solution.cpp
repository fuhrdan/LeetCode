#include <vector>
#include <cstdlib>
using namespace std;class Solution{vector<int>o;public:Solution(vector<int>&a):o(a){}vector<int> reset(){return o;}vector<int> shuffle(){auto a=o;for(int i=a.size()-1;i>0;i--){int j=rand()%(i+1);swap(a[i],a[j]);}return a;}};
