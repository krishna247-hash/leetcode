class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        set<int> st;
        unordered_map<int,int> mp;
        for(int i = 0; i < nums.size(); i++)
        {
            st.insert(nums[i]);
            mp[nums[i]]++;
        }
        int cnt = 0;
        for(auto it : st)
        {
            if(mp[it] > cnt)
            {
                cnt = mp[it];
            }
        }
        vector<vector<int>> ans;
        while(cnt--)
        {
            vector<int> temp;
            for(auto it: st)
            {
                if(mp[it] > 0)
                {
                    temp.push_back(it);
                    mp[it]--;
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};