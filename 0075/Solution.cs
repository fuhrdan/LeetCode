public class Solution{public void SortColors(int[]a){int l=0,i=0,r=a.Length-1;while(i<=r){if(a[i]==0){(a[l],a[i])=(a[i],a[l]);l++;i++;}else if(a[i]==2){(a[i],a[r])=(a[r],a[i]);r--;}else i++;}}}
