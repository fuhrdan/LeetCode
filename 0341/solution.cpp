#include <vector>
#include <stack>
using namespace std;class NestedIterator{stack<NestedInteger>st;void prep(){while(!st.empty()&&!st.top().isInteger()){auto v=st.top().getList();st.pop();for(int i=v.size()-1;i>=0;i--)st.push(v[i]);}}public:NestedIterator(vector<NestedInteger>&a){for(int i=a.size()-1;i>=0;i--)st.push(a[i]);}int next(){prep();int x=st.top().getInteger();st.pop();return x;}bool hasNext(){prep();return!st.empty();}};
