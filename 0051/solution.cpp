#include <vector>
#include <string>
using namespace std;class Solution{vector<vector<string>>o;void f(int n,int r,int c,int d1,int d2,vector<string>&b){if(r==n){o.push_back(b);return;}int a=((1<<n)-1)&~(c|d1|d2);while(a){int bit=a&-a;a-=bit;int col=__builtin_ctz(bit);b[r][col]='Q';f(n,r+1,c|bit,(d1|bit)<<1,(d2|bit)>>1,b);b[r][col]='.';}}public:vector<vector<string>> solveNQueens(int n){vector<string>b(n,string(n,'.'));f(n,0,0,0,0,b);return o;}};
