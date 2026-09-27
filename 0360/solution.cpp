#include <vector>
using namespace std;class Solution{int f(int x,int a,int b,int c){return a*x*x+b*x+c;}public:vector<int> sortTransformedArray(vector<int>&n,int a,int b,int c){vector<int>r(n.size());int l=0,h=n.size()-1,k=a>=0?n.size()-1:0;while(l<=h){int x=f(n[l],a,b,c),y=f(n[h],a,b,c);if(a>=0){if(x>y)r[k--]=x,l++;else r[k--]=y,h--;}else{if(x<y)r[k++]=x,l++;else r[k++]=y,h--;}}return r;}};
