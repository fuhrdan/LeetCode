public class Solution{public int MinPatches(int[]a,int n){long miss=1;int i=0,c=0;while(miss<=n){if(i<a.Length&&a[i]<=miss)miss+=a[i++];else{miss+=miss;c++;}}return c;}}
