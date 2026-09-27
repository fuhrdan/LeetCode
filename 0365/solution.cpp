#include <numeric>
class Solution{public:bool canMeasureWater(int x,int y,int z){return z==0||((long long)x+y>=z&&z%std::gcd(x,y)==0);}};
