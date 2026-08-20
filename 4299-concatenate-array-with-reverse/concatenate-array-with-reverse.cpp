class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        int n = nums.size();
        // vector<int> ans;
        // for(auto it : nums){
        //     ans.push_back(it);
        // }
        for(int i = n - 1; i >= 0; i--){
            nums.push_back(nums[i]);
        }

        // return ans;
        return nums;

    
    }
};