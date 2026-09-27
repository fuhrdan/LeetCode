int maxProduct(int*a,int n){int mx=a[0],mn=a[0],best=a[0];for(int i=1;i<n;i++){int x=a[i];if(x<0){int t=mx;mx=mn;mn=t;}mx=x>mx*x?x:mx*x;mn=x<mn*x?x:mn*x;if(mx>best)best=mx;}return best;}
