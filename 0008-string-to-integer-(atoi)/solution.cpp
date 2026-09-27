#include <string>
#include <climits>
using namespace std;
class Solution{public:int myAtoi(string s){int i=0,sign=1,r=0;while(i<(int)s.size()&&s[i]==' ')i++;if(i<(int)s.size()&&(s[i]=='+'||s[i]=='-')){if(s[i++]=='-')sign=-1;}while(i<(int)s.size()&&isdigit((unsigned char)s[i])){int d=s[i++]-'0';if(sign>0){if(r>INT_MAX/10||(r==INT_MAX/10&&d>7))return INT_MAX;r=r*10+d;}else{if(r<INT_MIN/10||(r==INT_MIN/10&&d>8))return INT_MIN;r=r*10-d;}}return r;}};
