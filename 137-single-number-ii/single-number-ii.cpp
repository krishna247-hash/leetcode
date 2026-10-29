class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> a(32,0);

        for(int i = 0; i <= 31; i++)
        {
            for(auto it: nums)
            {
                if(it&(1<<i))a[i]++;
            }
        }

        int ans = 0;
        for(int i = 0; i < 32; i++)
        {
            if(a[i] % 3 != 0)
            {
                ans += (1 << i);
            }
        }

        return ans;
    }
};