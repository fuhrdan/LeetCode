#include <string>
#include <unordered_map>
using namespace std;class Logger{unordered_map<string,int>m;public:Logger(){}bool shouldPrintMessage(int t,string s){if(!m.count(s)||t-m[s]>=10){m[s]=t;return true;}return false;}};
