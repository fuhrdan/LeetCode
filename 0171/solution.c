int titleToNumber(char*s){int r=0;for(int i=0;s[i];i++)r=r*26+s[i]-'A'+1;return r;}
