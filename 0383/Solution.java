class Solution{public boolean canConstruct(String r,String m){int[]c=new int[26];for(char x:m.toCharArray())c[x-'a']++;for(char x:r.toCharArray())if(--c[x-'a']<0)return false;return true;}}
