public class Solution{public double MyPow(double x,int n){long e=n;if(e<0){x=1/x;e=-e;}double r=1;while(e>0){if((e&1)==1)r*=x;x*=x;e>>=1;}return r;}}
