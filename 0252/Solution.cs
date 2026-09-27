using System;public class Solution{public bool CanAttendMeetings(int[][]a){Array.Sort(a,(x,y)=>x[0].CompareTo(y[0]));for(int i=1;i<a.Length;i++)if(a[i][0]<a[i-1][1])return false;return true;}}
