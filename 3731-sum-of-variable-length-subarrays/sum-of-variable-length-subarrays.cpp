class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            int st = max(0 , i - nums[i]);
            int s = 0;
            for(int j = st; j <= i; j++){
                s += nums[j];
            }
            sum += s;
        }
        return sum;
    }
};