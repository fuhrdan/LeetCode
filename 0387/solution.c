int firstUniqChar(char*s){int c[26]={0};for(int i=0;s[i];i++)c[s[i]-'a']++;for(int i=0;s[i];i++)if(c[s[i]-'a']==1)return i;return-1;}
