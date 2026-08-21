class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        vector<vector<int>> temp;

        int n = nums.size();
        for(int i = 0;i < n;i++){
            int size = nums[i];

            mp[size].push_back(i);

            if(mp[size].size() == size){
                temp.push_back(mp[size]);
                mp[size].clear();

            }


        }
        return temp;
    }
};