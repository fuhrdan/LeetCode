public class Solution{public int TitleToNumber(string s){int r=0;foreach(char c in s)r=r*26+c-'A'+1;return r;}}
