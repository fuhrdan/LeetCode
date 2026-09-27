class Solution{public boolean canPermutePalindrome(String s){int[]c=new int[256];int odd=0;for(char x:s.toCharArray()){c[x]++;odd+=(c[x]&1)==1?1:-1;}return odd<=1;}}
