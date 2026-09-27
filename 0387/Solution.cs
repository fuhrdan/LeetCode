public class Solution{public int FirstUniqChar(string s){int[]c=new int[26];foreach(char x in s)c[x-'a']++;for(int i=0;i<s.Length;i++)if(c[s[i]-'a']==1)return i;return-1;}}
