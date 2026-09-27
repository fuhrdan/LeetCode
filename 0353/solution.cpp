#include <vector>
#include <deque>
#include <unordered_set>
#include <string>
using namespace std;class SnakeGame{int w,h,score=0;vector<vector<int>>food;deque<int>b;unordered_set<int>s;public:SnakeGame(int width,int height,vector<vector<int>>&f):w(width),h(height),food(f){b.push_front(0);s.insert(0);}int move(string d){int p=b.front(),r=p/w,c=p%w;if(d=="U")r--;else if(d=="D")r++;else if(d=="L")c--;else c++;if(r<0||c<0||r>=h||c>=w)return-1;int id=r*w+c;bool eat=score<food.size()&&food[score][0]==r&&food[score][1]==c;if(!eat){s.erase(b.back());b.pop_back();}if(s.count(id))return-1;b.push_front(id);s.insert(id);if(eat)score++;return score;}};
