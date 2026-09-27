#include <queue>
#include <vector>
using namespace std;class MedianFinder{priority_queue<int>lo;priority_queue<int,vector<int>,greater<int>>hi;public:MedianFinder(){}void addNum(int x){if(lo.empty()||x<=lo.top())lo.push(x);else hi.push(x);if(lo.size()>hi.size()+1){hi.push(lo.top());lo.pop();}else if(hi.size()>lo.size()){lo.push(hi.top());hi.pop();}}double findMedian(){return lo.size()==hi.size()?((double)lo.top()+hi.top())/2:lo.top();}};
