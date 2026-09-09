class Solution {
public:
     
     void combinations( int n, vector<int>& arr,vector<int>& map, vector<int>& temp,vector<vector<int>>& ans)
     {
        if(temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < n; i++)
        {
            if(map[i] == 0)
            {
                temp.push_back(arr[i]);
                map[i] = 1;
                combinations(n,arr,map,temp,ans);
                temp.pop_back();
                map[i] = 0;
            }
        }
     }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> map(n,0);
        combinations(n,nums,map,temp,ans);
        return ans;
    }
};