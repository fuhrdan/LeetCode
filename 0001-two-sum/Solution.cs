using System.Collections.Generic;
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        var pos=new Dictionary<int,int>();
        for(int i=0;i<nums.Length;i++){
            int need=target-nums[i];
            if(pos.TryGetValue(need,out int j)) return new[]{j,i};
            pos[nums[i]]=i;
        }
        return new int[0];
    }
}
