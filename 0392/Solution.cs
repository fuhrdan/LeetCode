public class Solution{public bool IsSubsequence(string s,string t){int i=0;foreach(char c in t)if(i<s.Length&&s[i]==c)i++;return i==s.Length;}}
