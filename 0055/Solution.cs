using System;public class Solution{public bool CanJump(int[]a){int f=0;for(int i=0;i<a.Length;i++){if(i>f)return false;f=Math.Max(f,i+a[i]);}return true;}}
