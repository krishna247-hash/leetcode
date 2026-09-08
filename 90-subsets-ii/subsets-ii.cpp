class Solution {
public:
    
    void subsets(int i, int n, vector<int>& arr,vector<int>& temp ,set<vector<int>>& st)
    {
       if(i >= n)
       {
         if(i == n)
        {
            st.insert(temp);
        }
        return;
       }

       temp.push_back(arr[i]);
       subsets(i+1,n,arr,temp,st);
       temp.pop_back();
       subsets(i+1,n,arr,temp,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> temp;
        set<vector<int>> st;
        vector<vector<int>> ans;

        subsets(0,n,nums,temp,st);

        for(auto it: st)
        {
            ans.push_back(it);
        }
        return ans;
        
    }
};