#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>
using namespace std;class RandomizedCollection{vector<int>a;unordered_map<int,unordered_set<int>>m;public:RandomizedCollection(){}bool insert(int v){bool fresh=m[v].empty();m[v].insert(a.size());a.push_back(v);return fresh;}bool remove(int v){if(!m.count(v)||m[v].empty())return false;int i=*m[v].begin();m[v].erase(i);int last=a.back();int li=a.size()-1;a[i]=last;if(i!=li){m[last].erase(li);m[last].insert(i);}a.pop_back();return true;}int getRandom(){return a[rand()%a.size()];}};
