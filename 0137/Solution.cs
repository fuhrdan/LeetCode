public class Solution{public int SingleNumber(int[]a){int o=0,t=0;foreach(int x in a){o=(o^x)&~t;t=(t^x)&~o;}return o;}}
