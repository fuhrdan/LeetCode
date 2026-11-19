#include <algorithm>
#include <vector>

class Solution {
public:
    // LeetCode 2567. Modifies nums by sorting it in place.
    int minimizeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        const int n = static_cast<int>(nums.size());

        return std::min({
            nums[n - 3] - nums[0],  // Change the two largest elements.
            nums[n - 2] - nums[1],  // Change one at each end.
            nums[n - 1] - nums[2]   // Change the two smallest elements.
        });
    }
};
