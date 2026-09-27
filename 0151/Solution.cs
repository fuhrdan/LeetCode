using System.Linq;public class Solution{public string ReverseWords(string s)=>string.Join(" ",s.Split((char[])null,System.StringSplitOptions.RemoveEmptyEntries).Reverse());}
