int canCompleteCircuit(int*g,int n,int*c,int cs){int total=0,tank=0,start=0;for(int i=0;i<n;i++){int d=g[i]-c[i];total+=d;tank+=d;if(tank<0){start=i+1;tank=0;}}return total>=0?start:-1;}
