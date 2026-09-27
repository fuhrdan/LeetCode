public class Solution{public bool CanConstruct(string r,string m){int[]c=new int[26];foreach(char x in m)c[x-'a']++;foreach(char x in r)if(--c[x-'a']<0)return false;return true;}}
