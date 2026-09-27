#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> pos;
        for(int i=0;i<(int)nums.size();++i){
            auto it=pos.find(target-nums[i]);
            if(it!=pos.end()) return {it->second,i};
            pos[nums[i]]=i;
        }
        return {};
    }
};
