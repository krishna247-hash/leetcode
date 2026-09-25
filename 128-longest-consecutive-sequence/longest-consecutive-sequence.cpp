class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 0;
        for(auto it: st)
        {
            int x = it;
            if(st.find(x - 1) == st.end())
            {
                int cnt = 1;
                while(st.find(x + 1) != st.end())
                {
                  x++;
                    cnt++;
                }
                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};