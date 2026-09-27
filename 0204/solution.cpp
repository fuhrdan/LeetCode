#include <vector>
using namespace std;class Solution{public:int countPrimes(int n){vector<char>c(n);int r=0;for(int i=2;i<n;i++)if(!c[i]){r++;if((long long)i*i<n)for(int j=i*i;j<n;j+=i)c[j]=1;}return r;}};
