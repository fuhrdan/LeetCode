public class Solution{public int RangeBitwiseAnd(int left,int right){int s=0;while(left<right){left>>=1;right>>=1;s++;}return left<<s;}}
