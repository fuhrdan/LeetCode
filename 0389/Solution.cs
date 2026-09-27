public class Solution{public char FindTheDifference(string s,string t){char x='\0';foreach(char c in s)x^=c;foreach(char c in t)x^=c;return x;}}
