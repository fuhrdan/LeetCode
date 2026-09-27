class Solution {
    public String minWindow(String s, String t) {
        int[] need=new int[128]; int missing=t.length(),l=0,bestL=0,best=Integer.MAX_VALUE;
        for(char c:t.toCharArray()) need[c]++;
        for(int r=0;r<s.length();r++){
            char c=s.charAt(r); if(need[c]>0) missing--; need[c]--;
            while(missing==0){
                if(r-l+1<best){best=r-l+1;bestL=l;}
                c=s.charAt(l++); need[c]++; if(need[c]>0) missing++;
            }
        }
        return best==Integer.MAX_VALUE?"":s.substring(bestL,bestL+best);
    }
}
