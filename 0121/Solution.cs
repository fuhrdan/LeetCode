using System;public class Solution{public int MaxProfit(int[]p){int mn=int.MaxValue,b=0;foreach(int x in p){mn=Math.Min(mn,x);b=Math.Max(b,x-mn);}return b;}}
