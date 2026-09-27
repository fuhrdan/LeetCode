#include <unordered_map>
using namespace std;class TwoSum{unordered_map<int,int>m;public:TwoSum(){}void add(int x){m[x]++;}bool find(int v){for(auto [x,c]:m){int y=v-x;if(m.count(y)&&(y!=x||c>1))return true;}return false;}};
