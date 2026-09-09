class Solution {
public:


    void combinations(int j, int n, int k, vector<int>& temp,vector<vector<int>>& ans)
    {
        if(temp.size() == k)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = j; i <= n; i++)
        {
                temp.push_back(i);
                combinations(i+1,n,k,temp,ans);
                temp.pop_back();
        }
    }


    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        combinations(1,n,k,temp,ans);

        return ans;
    }
};