class Solution{public void wiggleSort(int[]a){for(int i=1;i<a.length;i++)if((i%2==1&&a[i]<a[i-1])||(i%2==0&&a[i]>a[i-1])){int t=a[i];a[i]=a[i-1];a[i-1]=t;}}}
