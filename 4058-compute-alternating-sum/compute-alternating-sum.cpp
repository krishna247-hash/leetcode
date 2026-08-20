class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int sum = 0;

        while(i < n-1 ){
            sum = sum + nums[i++];
            sum = sum - nums[i++];

            
        }
        if(i == n-1) sum = sum + nums[i];
        return sum;
    }
};