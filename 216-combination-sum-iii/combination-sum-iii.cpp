class Solution {
public:
    
    
   void combination(int i, int sum, int n, int k, vector<int>& temp, vector<vector<int>>& ans)
 {
    if(sum > n) return;
    if(i > 9 || temp.size() >= k)
    {
        if(temp.size() == k && sum == n) ans.push_back(temp);
        return;
    }

    temp.push_back(i);
    sum += i;
    combination(i+1,sum,n,k,temp,ans);
    temp.pop_back();
    sum -= i;
     combination(i+1,sum,n,k,temp,ans);

 }

 vector<vector<int>> combinationSum3(int k, int n) {

        vector<int> temp;
        vector<vector<int>> ans;
        combination(1,0,n,k,temp,ans);

        return ans;
    }
};