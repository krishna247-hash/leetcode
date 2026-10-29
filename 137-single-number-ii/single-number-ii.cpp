class Solution {
public:
    int singleNumber(vector<int>& nums) {
        

        int ans = 0;
        for(int i = 0; i <= 31; i++)
        {
            int a = 0;
            for(auto it: nums)
            {
                if(it&(1<<i))a++;
            }
            if(a % 3 != 0)
            {
                ans += (1 << i);
            }
        }

        return ans;
    }
};