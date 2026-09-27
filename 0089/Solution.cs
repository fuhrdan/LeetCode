using System.Collections.Generic;public class Solution{public IList<int> GrayCode(int n){var r=new List<int>();for(int i=0;i<(1<<n);i++)r.Add(i^(i>>1));return r;}}
