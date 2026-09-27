#include <string>
#include <unordered_map>
using namespace std;class Solution{public:string fractionToDecimal(int n,int d){if(!n)return"0";long long a=n,b=d;string r;if((a<0)^(b<0))r+='-';a=llabs(a);b=llabs(b);r+=to_string(a/b);long long rem=a%b;if(!rem)return r;r+='.';unordered_map<long long,int>m;while(rem){if(m.count(rem)){r.insert(m[rem],"(");r+=')';break;}m[rem]=r.size();rem*=10;r+=char('0'+rem/b);rem%=b;}return r;}};
