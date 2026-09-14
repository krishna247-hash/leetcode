class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_map<int,int> mp;
       for(auto it : nums)
       {
        mp[it]++;
       }
       vector<pair<int,int>> temp;

       for(auto it: mp)
       {
        temp.push_back({it.second , it.first});
       }
       sort(temp.begin(),temp.end());
       reverse(temp.begin(),temp.end());
       vector<int> ans;
       for(int i = 0; i < k; i++)
       {
        ans.push_back(temp[i].second);
       }
       return ans;
    }
};