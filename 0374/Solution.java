public class Solution extends GuessGame{public int guessNumber(int n){long l=1,r=n;while(l<=r){int m=(int)(l+(r-l)/2),g=guess(m);if(g==0)return m;if(g<0)r=m-1;else l=m+1;}return-1;}}
