class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int e1 = INT_MIN;

        int e2 = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= e1){
                e2 = e1;

                e1 = nums[i];
            }
            else if(nums[i] > e2)
            {
                e2 = nums[i];
            }

        }

        int ans = (e1 - 1)*(e2 - 1);

        return ans;

    }
};