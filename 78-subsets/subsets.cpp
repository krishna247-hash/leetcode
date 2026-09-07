class Solution {
public:
    
    void sets(int i,vector<int>& nums, vector<int>& temp, int n , vector<vector<int>>& ans)
    {
        if(i == n)
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        sets(i+1,nums,temp,n,ans);
        temp.pop_back();
        sets(i+1,nums,temp,n,ans);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp; 
        sets(0,nums,temp,nums.size(),ans);
        return ans;
    }
};