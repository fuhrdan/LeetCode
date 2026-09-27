int findDuplicate(int*a,int n){int s=a[0],f=a[0];do{s=a[s];f=a[a[f]];}while(s!=f);s=a[0];while(s!=f){s=a[s];f=a[f];}return s;}
