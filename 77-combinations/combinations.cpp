class Solution {
public:


    void combinations(int j, int n, int k, vector<int>& temp, set<vector<int>>& st,vector<int>&mp)
    {
        if(temp.size() == k)
        {
            // vector<int> k = temp;
            // sort(k.begin(),k.end());
            st.insert(temp);
            return;
        }

        for(int i = j; i <= n; i++)
        {
            if(mp[i] == 0)
            {
                temp.push_back(i);
                mp[i] = 1;
                combinations(i+1,n,k,temp,st,mp);
                temp.pop_back();
                mp[i] = 0;
            }
        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> mp(n+1 , 0);
        vector<int> temp;
        set<vector<int>> st;
        vector<vector<int>> ans;
        combinations(1,n,k,temp,st,mp);
        for(auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};