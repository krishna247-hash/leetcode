class Solution {
public:
   void func(int n , int sum,vector<int>& temp,vector<int>& arr,set<vector<int>>& st, int target)
{
    if(sum >= target)
    {
        if(sum == target)
        {
            vector<int> krish = temp;
            sort(krish.begin(),krish.end());
            st.insert(krish);
        }
        return;
    }

    for(int i = 0; i < n; i++)
    {
        temp.push_back(arr[i]);
        sum += arr[i];

        func(n,sum,temp,arr,st,target);

        temp.pop_back();

        sum -= arr[i];
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        set<vector<int>> st;
        vector<int> temp;
        int sum = 0;
        vector<vector<int>> ans;
        func(n,sum,temp,candidates,st,target);

        for(auto it : st)
        {
            ans.push_back(it);
        }
        
        return ans;
    }
};