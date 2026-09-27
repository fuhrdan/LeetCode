class Solution{int next(int n){int s=0;while(n>0){int d=n%10;s+=d*d;n/=10;}return s;}public boolean isHappy(int n){int a=n,b=n;do{a=next(a);b=next(next(b));}while(a!=b);return a==1;}}
