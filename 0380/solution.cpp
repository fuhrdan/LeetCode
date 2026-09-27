#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std;class RandomizedSet{vector<int>a;unordered_map<int,int>m;public:RandomizedSet(){}bool insert(int v){if(m.count(v))return false;m[v]=a.size();a.push_back(v);return true;}bool remove(int v){if(!m.count(v))return false;int i=m[v],x=a.back();a[i]=x;m[x]=i;a.pop_back();m.erase(v);return true;}int getRandom(){return a[rand()%a.size()];}};
