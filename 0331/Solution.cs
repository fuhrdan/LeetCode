public class Solution{public bool IsValidSerialization(string s){int slots=1;foreach(string x in s.Split(',')){if(slots==0)return false;slots--;if(x!="#")slots+=2;}return slots==0;}}
