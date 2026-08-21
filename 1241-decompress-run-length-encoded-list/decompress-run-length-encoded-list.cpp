class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> temp;
        while(i < n){
            int t = nums[i++];
            while(t != 0){
                temp.push_back(nums[i]);
                t--;
            }
            i++;
        }
        return temp;

     }
};