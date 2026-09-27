#include <unordered_map>
using namespace std;class Solution{unordered_map<Node*,Node*>m;public:Node* cloneGraph(Node*n){if(!n)return nullptr;if(m.count(n))return m[n];Node*c=new Node(n->val);m[n]=c;for(auto x:n->neighbors)c->neighbors.push_back(cloneGraph(x));return c;}};
