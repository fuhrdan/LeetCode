class Solution{public:int read(char*buf,int n){char t[4];int got=0;while(got<n){int k=read4(t);if(!k)break;for(int i=0;i<k&&got<n;i++)buf[got++]=t[i];}return got;}};
