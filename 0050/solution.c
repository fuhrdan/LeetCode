double myPow(double x,int n){long long e=n;if(e<0){x=1/x;e=-e;}double r=1;while(e){if(e&1)r*=x;x*=x;e>>=1;}return r;}
