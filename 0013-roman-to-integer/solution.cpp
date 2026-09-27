#include <string>
using namespace std;
class Solution{int v(char c){string s="IVXLCDM";int a[]={1,5,10,50,100,500,1000};return a[s.find(c)];}public:int romanToInt(string s){int r=0;for(int i=0;i<(int)s.size();i++){int a=v(s[i]),b=i+1<(int)s.size()?v(s[i+1]):0;r+=a<b?-a:a;}return r;}};
