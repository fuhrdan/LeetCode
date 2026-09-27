class Solution{public int[] singleNumber(int[]a){int x=0;for(int v:a)x^=v;int b=x&-x,p=0,q=0;for(int v:a)if((v&b)!=0)p^=v;else q^=v;return new int[]{p,q};}}
