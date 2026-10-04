class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        if(n != 1 && nums[0] == 0) return false;
        vector<int> arr;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
            {
                arr.push_back(i);
            }
        }

        for(auto it: arr)
        {
            bool flag = 1;
            for(int i = 0; i <= it; i++)
            {
                if(it != n - 1 && nums[i] > (it - i)) flag = 0;
                if(it == n - 1 && nums[i] >= (it - i)) flag = 0;
            }

            if(flag) return false;
        }
        
        return true;
    }
};