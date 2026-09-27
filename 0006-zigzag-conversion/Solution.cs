using System.Text;
public class Solution {
    public string Convert(string s,int rows){
        if(rows==1||rows>=s.Length)return s; var o=new StringBuilder(); int cycle=2*rows-2;
        for(int r=0;r<rows;r++) for(int i=r;i<s.Length;i+=cycle){o.Append(s[i]);int j=i+cycle-2*r;if(r>0&&r<rows-1&&j<s.Length)o.Append(s[j]);}
        return o.ToString();
    }
}
