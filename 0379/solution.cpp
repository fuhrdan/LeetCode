#include <queue>
#include <vector>
using namespace std;class PhoneDirectory{queue<int>q;vector<bool>used;public:PhoneDirectory(int n):used(n){for(int i=0;i<n;i++)q.push(i);}int get(){if(q.empty())return-1;int x=q.front();q.pop();used[x]=true;return x;}bool check(int n){return n>=0&&n<used.size()&&!used[n];}void release(int n){if(n>=0&&n<used.size()&&used[n]){used[n]=false;q.push(n);}}};
