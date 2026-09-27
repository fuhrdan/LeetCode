public class Solution{public bool IsAnagram(string s,string t){int[]c=new int[26];foreach(char x in s)c[x-'a']++;foreach(char x in t)c[x-'a']--;foreach(int x in c)if(x!=0)return false;return true;}}
