public class Solution{public int MajorityElement(int[]a){int c=0,x=0;foreach(int v in a){if(c==0)x=v;c+=v==x?1:-1;}return x;}}
