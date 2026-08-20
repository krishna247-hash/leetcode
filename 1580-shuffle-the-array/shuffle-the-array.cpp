class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> temp;
        for(int i = 0,j = n; j < 2*n && i < n;i++,j++){
            temp.push_back(nums[i]);
            temp.push_back(nums[j]);

        }
        return temp;
    }
};