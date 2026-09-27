int getSum(int a,int b){while(b){unsigned c=((unsigned)a&(unsigned)b)<<1;a^=b;b=(int)c;}return a;}
