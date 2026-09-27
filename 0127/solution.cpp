#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;class Solution{public:int ladderLength(string b,string e,vector<string>&wl){unordered_set<string>d(wl.begin(),wl.end());if(!d.count(e))return 0;queue<pair<string,int>>q;q.push({b,1});d.erase(b);while(!q.empty()){auto [w,step]=q.front();q.pop();if(w==e)return step;for(int i=0;i<w.size();i++){char old=w[i];for(char c='a';c<='z';c++){w[i]=c;if(d.erase(w))q.push({w,step+1});}w[i]=old;}}return 0;}};
