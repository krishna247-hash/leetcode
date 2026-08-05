class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int len = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                len++;
                maxi = max( maxi , len );
            }
            else{
                len =0;
            }
        }
        return maxi;
        
    }
};