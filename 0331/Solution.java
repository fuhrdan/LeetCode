class Solution{public boolean isValidSerialization(String s){int slots=1;for(String x:s.split(",")){if(slots==0)return false;slots--;if(!x.equals("#"))slots+=2;}return slots==0;}}
