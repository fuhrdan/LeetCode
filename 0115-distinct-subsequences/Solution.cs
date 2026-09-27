public class Solution{public int NumDistinct(string s,string t){long[]d=new long[t.Length+1];d[0]=1;foreach(char c in s)for(int j=t.Length-1;j>=0;j--)if(c==t[j])d[j+1]+=d[j];return(int)d[t.Length];}}
