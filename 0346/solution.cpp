#include <queue>
using namespace std;class MovingAverage{queue<int>q;int cap;long long sum=0;public:MovingAverage(int size):cap(size){}double next(int val){q.push(val);sum+=val;if(q.size()>cap){sum-=q.front();q.pop();}return(double)sum/q.size();}};
