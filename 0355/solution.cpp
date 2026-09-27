#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;class Twitter{long long tm=0;unordered_map<int,vector<pair<long long,int>>>tw;unordered_map<int,unordered_set<int>>fo;public:Twitter(){}void postTweet(int u,int id){tw[u].push_back({tm++,id});}vector<int> getNewsFeed(int u){vector<pair<long long,int>>a=tw[u];for(int v:fo[u])for(auto x:tw[v])a.push_back(x);sort(a.rbegin(),a.rend());vector<int>o;for(int i=0;i<a.size()&&i<10;i++)o.push_back(a[i].second);return o;}void follow(int a,int b){if(a!=b)fo[a].insert(b);}void unfollow(int a,int b){fo[a].erase(b);}};
