#include <string>
using namespace std;
class Solution {
public:
    string convert(string s,int rows){
        if(rows==1||rows>=(int)s.size()) return s;
        string out; int cycle=2*rows-2,n=s.size();
        for(int r=0;r<rows;r++) for(int i=r;i<n;i+=cycle){ out+=s[i]; int j=i+cycle-2*r; if(r&&r<rows-1&&j<n) out+=s[j]; }
        return out;
    }
};
