int wiggleMaxLength(int*a,int n){if(!n)return 0;int up=1,down=1;for(int i=1;i<n;i++){if(a[i]>a[i-1])up=down+1;else if(a[i]<a[i-1])down=up+1;}return up>down?up:down;}
