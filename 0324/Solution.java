import java.util.*;class Solution{public void wiggleSort(int[]a){int[]b=a.clone();Arrays.sort(b);int l=(a.length-1)/2,r=a.length-1;for(int i=0;i<a.length;i++)a[i]=i%2==0?b[l--]:b[r--];}}
