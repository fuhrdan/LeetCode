public class Solution{public int LengthOfLastWord(string s){int i=s.Length-1;while(i>=0&&s[i]==' ')i--;int e=i;while(i>=0&&s[i]!=' ')i--;return e-i;}}
