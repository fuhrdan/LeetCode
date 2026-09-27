import java.util.*;class Solution{public List<Integer> grayCode(int n){List<Integer>r=new ArrayList<>();for(int i=0;i<(1<<n);i++)r.add(i^(i>>1));return r;}}
