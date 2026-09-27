class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int retNum = (int) nums.size();
        unordered_map<int, int> alwaysGiveGood;
        for(int x = 0; x < retNum; x++)
        {
            int compliment = target - nums[x]; // I'm playing with words here.  complement vs. compliment
            if(alwaysGiveGood.count(compliment))
            {
                return {x, alwaysGiveGood[compliment]};
            }
            alwaysGiveGood[nums[x]] = x;
        }
        return {-1, -1};
    }
};