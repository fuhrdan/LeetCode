public class Solution{public void WiggleSort(int[]a){for(int i=1;i<a.Length;i++)if((i%2==1&&a[i]<a[i-1])||(i%2==0&&a[i]>a[i-1]))(a[i],a[i-1])=(a[i-1],a[i]);}}
