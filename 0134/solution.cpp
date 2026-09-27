#include <vector>
using namespace std;class Solution{public:int canCompleteCircuit(vector<int>&g,vector<int>&c){int total=0,tank=0,start=0;for(int i=0;i<g.size();i++){int d=g[i]-c[i];total+=d;tank+=d;if(tank<0){start=i+1;tank=0;}}return total>=0?start:-1;}};
