public class Solution{public bool IncreasingTriplet(int[]a){int x=int.MaxValue,y=int.MaxValue;foreach(int v in a)if(v<=x)x=v;else if(v<=y)y=v;else return true;return false;}}
