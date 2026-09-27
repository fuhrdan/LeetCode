public class Solution{public int[] SingleNumber(int[]a){int x=0;foreach(int v in a)x^=v;int b=x&-x,p=0,q=0;foreach(int v in a)if((v&b)!=0)p^=v;else q^=v;return new[]{p,q};}}
