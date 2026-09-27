public class Solution{public bool CanPermutePalindrome(string s){int[]c=new int[256];int odd=0;foreach(char x in s){c[x]++;odd+=(c[x]&1)==1?1:-1;}return odd<=1;}}
