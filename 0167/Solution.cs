public class Solution{public int[] TwoSum(int[]a,int t){int l=0,r=a.Length-1;while(l<r){int s=a[l]+a[r];if(s==t)return new[]{l+1,r+1};if(s<t)l++;else r--;}return new int[0];}}
