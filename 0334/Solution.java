class Solution{public boolean increasingTriplet(int[]a){int x=Integer.MAX_VALUE,y=Integer.MAX_VALUE;for(int v:a)if(v<=x)x=v;else if(v<=y)y=v;else return true;return false;}}
