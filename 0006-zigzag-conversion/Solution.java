class Solution {
    public String convert(String s,int rows){
        if(rows==1||rows>=s.length()) return s;
        StringBuilder out=new StringBuilder(); int cycle=2*rows-2;
        for(int r=0;r<rows;r++) for(int i=r;i<s.length();i+=cycle){ out.append(s.charAt(i)); int j=i+cycle-2*r; if(r>0&&r<rows-1&&j<s.length())out.append(s.charAt(j)); }
        return out.toString();
    }
}
