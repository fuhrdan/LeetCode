#include <vector>
#include <algorithm>
using namespace std;class MinStack{vector<pair<int,int>>s;public:MinStack(){}void push(int x){s.push_back({x,s.empty()?x:min(x,s.back().second)});}void pop(){s.pop_back();}int top(){return s.back().first;}int getMin(){return s.back().second;}};
