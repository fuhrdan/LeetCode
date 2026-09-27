class Solution{int g(int a,int b){while(b!=0){int t=a%b;a=b;b=t;}return a;}public boolean canMeasureWater(int x,int y,int z){return z==0||((long)x+y>=z&&z%g(x,y)==0);}}
