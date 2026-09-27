import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] last=new int[256]; Arrays.fill(last,-1); int left=0,best=0;
        for(int r=0;r<s.length();r++){ int c=s.charAt(r); left=Math.max(left,last[c]+1); last[c]=r; best=Math.max(best,r-left+1); }
        return best;
    }
}
