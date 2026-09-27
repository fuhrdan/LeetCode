#include <list>
#include <unordered_map>
using namespace std;class LRUCache{int cap;list<pair<int,int>>q;unordered_map<int,list<pair<int,int>>::iterator>m;public:LRUCache(int capacity):cap(capacity){}int get(int k){if(!m.count(k))return-1;auto it=m[k];int v=it->second;q.splice(q.begin(),q,it);return v;}void put(int k,int v){if(m.count(k)){auto it=m[k];it->second=v;q.splice(q.begin(),q,it);return;}if(q.size()==cap){m.erase(q.back().first);q.pop_back();}q.push_front({k,v});m[k]=q.begin();}};
