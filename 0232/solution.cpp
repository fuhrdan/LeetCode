#include <stack>
using namespace std;class MyQueue{stack<int>a,b;void m(){if(b.empty())while(!a.empty()){b.push(a.top());a.pop();}}public:MyQueue(){}void push(int x){a.push(x);}int pop(){m();int x=b.top();b.pop();return x;}int peek(){m();return b.top();}bool empty(){return a.empty()&&b.empty();}};
