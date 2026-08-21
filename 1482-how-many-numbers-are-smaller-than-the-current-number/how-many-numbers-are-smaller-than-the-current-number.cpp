class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> temp;

        for(auto it: nums){
            int cnt = 0;
            for(auto x: nums){
                if(x < it) cnt++;

            }
            temp.push_back(cnt);
        }
        return temp;
    }
};