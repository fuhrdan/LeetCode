#include <vector>
using namespace std;class Solution{ListNode*m(ListNode*a,ListNode*b){ListNode d,*t=&d;while(a&&b){if(a->val<=b->val){t->next=a;a=a->next;}else{t->next=b;b=b->next;}t=t->next;}t->next=a?a:b;return d.next;}public:ListNode* mergeKLists(vector<ListNode*>&v){if(v.empty())return nullptr;for(int s=1;s<v.size();s*=2)for(int i=0;i+s<v.size();i+=2*s)v[i]=m(v[i],v[i+s]);return v[0];}};
