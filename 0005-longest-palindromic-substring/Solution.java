class Solution {
    public String longestPalindrome(String s){
        int n=s.length(),bestL=0,best=1;
        for(int c=0;c<n;c++) for(int t=0;t<2;t++){
            int l=c,r=c+t; while(l>=0&&r<n&&s.charAt(l)==s.charAt(r)){ if(r-l+1>best){best=r-l+1;bestL=l;} l--;r++; }
        }
        return s.substring(bestL,bestL+best);
    }
}
