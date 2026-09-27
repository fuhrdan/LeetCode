#include <vector>
using namespace std;class Solution{public:bool isValidSudoku(vector<vector<char>>&b){int r[9]{},c[9]{},q[9]{};for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(b[i][j]!='.'){int bit=1<<(b[i][j]-'1'),k=i/3*3+j/3;if((r[i]&bit)||(c[j]&bit)||(q[k]&bit))return false;r[i]|=bit;c[j]|=bit;q[k]|=bit;}return true;}};
