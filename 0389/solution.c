char findTheDifference(char*s,char*t){char x=0;for(int i=0;s[i];i++)x^=s[i];for(int i=0;t[i];i++)x^=t[i];return x;}
