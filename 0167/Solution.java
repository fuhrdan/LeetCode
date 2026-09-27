class Solution{public int[] twoSum(int[]a,int t){int l=0,r=a.length-1;while(l<r){int s=a[l]+a[r];if(s==t)return new int[]{l+1,r+1};if(s<t)l++;else r--;}return new int[0];}}
