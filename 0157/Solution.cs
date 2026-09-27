public class Solution : Reader4{public int Read(char[]buf,int n){char[]t=new char[4];int got=0;while(got<n){int k=Read4(t);if(k==0)break;for(int i=0;i<k&&got<n;i++)buf[got++]=t[i];}return got;}}
