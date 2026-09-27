#include <queue>
using namespace std;class HitCounter{queue<int>q;public:HitCounter(){}void hit(int t){q.push(t);}int getHits(int t){while(!q.empty()&&q.front()<=t-300)q.pop();return q.size();}};
