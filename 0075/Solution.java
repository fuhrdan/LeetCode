class Solution{public void sortColors(int[]a){int l=0,i=0,r=a.length-1;while(i<=r){if(a[i]==0){int t=a[l];a[l++]=a[i];a[i++]=t;}else if(a[i]==2){int t=a[r];a[r--]=a[i];a[i]=t;}else i++;}}}
