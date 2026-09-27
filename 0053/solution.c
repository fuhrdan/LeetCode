int maxSubArray(int*a,int n){int cur=a[0],best=a[0];for(int i=1;i<n;i++){cur=a[i]>cur+a[i]?a[i]:cur+a[i];if(cur>best)best=cur;}return best;}
