class Solution{public int canCompleteCircuit(int[]g,int[]c){int total=0,tank=0,st=0;for(int i=0;i<g.length;i++){int d=g[i]-c[i];total+=d;tank+=d;if(tank<0){st=i+1;tank=0;}}return total>=0?st:-1;}}
