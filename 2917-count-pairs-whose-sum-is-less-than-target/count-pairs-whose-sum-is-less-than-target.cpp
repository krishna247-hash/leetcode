class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        int i = 0;
        int j = n-1;

        sort(nums.begin(),nums.end());

        while(i < j){
            if(nums[i] + nums[j] < target){
                cnt += j-i;
                i++;
            }
            else{
                j--;
            }
        }

        return cnt;
    }
};