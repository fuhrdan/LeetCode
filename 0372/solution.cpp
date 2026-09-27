#include <vector>
using namespace std;class Solution{int p(int a,int e){int r=1;a%=1337;while(e){if(e&1)r=r*a%1337;a=a*a%1337;e>>=1;}return r;}public:int superPow(int a,vector<int>&b){int r=1;for(int d:b)r=p(r,10)*p(a,d)%1337;return r;}};
