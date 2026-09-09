class Solution {
public:

    void combinations(vector<int>& arr, vector<int>& mp, set<vector<int>>& st, vector<int>& temp)
    {
        if(temp.size() == arr.size())
        {
            st.insert(temp);
            return;
        }

        for(int i = 0; i < arr.size(); i++)
        {
            if(mp[i] == 0)
            {
                mp[i] = 1;
                temp.push_back(arr[i]);
                combinations(arr,mp,st,temp);
                mp[i] = 0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<int> mp(nums.size()+1,0);
        vector<vector<int>> ans;
        set<vector<int>> st;
        combinations(nums,mp,st,temp);

        for(auto it : st)
        ans.push_back(it);

        return ans;
    }
};