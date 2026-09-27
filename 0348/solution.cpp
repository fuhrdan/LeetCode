#include <vector>
#include <cstdlib>
using namespace std;class TicTacToe{int n,d1=0,d2=0;vector<int>r,c;public:TicTacToe(int n):n(n),r(n),c(n){}int move(int row,int col,int player){int v=player==1?1:-1;r[row]+=v;c[col]+=v;if(row==col)d1+=v;if(row+col==n-1)d2+=v;if(abs(r[row])==n||abs(c[col])==n||abs(d1)==n||abs(d2)==n)return player;return 0;}};
