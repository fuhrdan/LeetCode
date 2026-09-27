int minPatches(int*a,int n,int target){long long miss=1;int i=0,c=0;while(miss<=target){if(i<n&&a[i]<=miss)miss+=a[i++];else{miss+=miss;c++;}}return c;}
