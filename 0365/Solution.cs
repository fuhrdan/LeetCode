public class Solution{int G(int a,int b){while(b!=0){int t=a%b;a=b;b=t;}return a;}public bool CanMeasureWater(int x,int y,int z)=>z==0||((long)x+y>=z&&z%G(x,y)==0);}
