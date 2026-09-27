class Solution{public int majorityElement(int[]a){int c=0,x=0;for(int v:a){if(c==0)x=v;c+=v==x?1:-1;}return x;}}
