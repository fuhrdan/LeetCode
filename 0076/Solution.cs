using System;
public class Solution {
    public string MinWindow(string s,string t){
        int[] need=new int[128]; int missing=t.Length,l=0,bestL=0,best=int.MaxValue;
        foreach(char c in t)need[c]++;
        for(int r=0;r<s.Length;r++){
            char c=s[r]; if(need[c]>0)missing--; need[c]--;
            while(missing==0){
                if(r-l+1<best){best=r-l+1;bestL=l;}
                c=s[l++]; need[c]++; if(need[c]>0)missing++;
            }
        }
        return best==int.MaxValue?"":s.Substring(bestL,best);
    }
}
