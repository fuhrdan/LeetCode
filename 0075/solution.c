void sortColors(int*a,int n){int l=0,i=0,r=n-1;while(i<=r){if(a[i]==0){int t=a[l];a[l++]=a[i];a[i++]=t;}else if(a[i]==2){int t=a[r];a[r--]=a[i];a[i]=t;}else i++;}}
