using System.Collections.Generic;public class Solution{public bool ContainsDuplicate(int[]a){var s=new HashSet<int>();foreach(int x in a)if(!s.Add(x))return true;return false;}}
