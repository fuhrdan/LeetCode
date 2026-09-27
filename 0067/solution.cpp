#include <string>
#include <algorithm>
using namespace std;class Solution{public:string addBinary(string a,string b){int i=a.size()-1,j=b.size()-1,c=0;string r;while(i>=0||j>=0||c){int s=c+(i>=0?a[i--]-'0':0)+(j>=0?b[j--]-'0':0);r+=char('0'+s%2);c=s/2;}reverse(r.begin(),r.end());return r;}};
