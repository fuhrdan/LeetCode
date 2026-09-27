public class Solution : Relation{public int FindCelebrity(int n){int c=0;for(int i=1;i<n;i++)if(Knows(c,i))c=i;for(int i=0;i<n;i++)if(i!=c&&(Knows(c,i)||!Knows(i,c)))return-1;return c;}}
