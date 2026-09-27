public class Solution{public int LastRemaining(int n){int h=1,s=1,left=n;bool lr=true;while(left>1){if(lr||left%2==1)h+=s;left/=2;s*=2;lr=!lr;}return h;}}
