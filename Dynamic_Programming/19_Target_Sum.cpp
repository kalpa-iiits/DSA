// We already have current index i, so we try finding remainder index 


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for(int i = 0; i<nums.size();i++){
            int rem = target - nums[i];
            if(mpp.find(rem) != mpp.end()){
                return {mpp[rem], i};   // {index of rem, index of current}
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};