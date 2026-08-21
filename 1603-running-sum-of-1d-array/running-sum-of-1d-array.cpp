class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> temp;
        int sum = 0;
        for(auto it: nums){
            sum += it;
            temp.push_back(sum);
        }
        return temp;

    }
};