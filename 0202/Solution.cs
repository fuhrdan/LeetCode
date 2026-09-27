public class Solution{int Next(int n){int s=0;while(n>0){int d=n%10;s+=d*d;n/=10;}return s;}public bool IsHappy(int n){int a=n,b=n;do{a=Next(a);b=Next(Next(b));}while(a!=b);return a==1;}}
