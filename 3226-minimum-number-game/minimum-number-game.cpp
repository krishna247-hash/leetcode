class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> arr;

        for(int i = 1; i < n; i += 2){

            arr.push_back(nums[i]);
            arr.push_back(nums[i-1]);
        }
        return arr;
    }
};