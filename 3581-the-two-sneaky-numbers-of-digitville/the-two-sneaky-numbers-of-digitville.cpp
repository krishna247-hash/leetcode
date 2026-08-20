class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
         vector<int> temp;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(auto it: nums){
            mp[it]++;
        }
       for(auto it: mp){
        if(it.second == 2){
            temp.push_back(it.first);
        }
       }


       return temp;
    }
};