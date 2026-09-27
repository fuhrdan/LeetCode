using System;
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        int[] last=new int[256]; Array.Fill(last,-1); int left=0,best=0;
        for(int r=0;r<s.Length;r++){ int c=s[r]; left=Math.Max(left,last[c]+1); last[c]=r; best=Math.Max(best,r-left+1); }
        return best;
    }
}
