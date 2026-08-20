class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < nums.size();i++){
            int sumL = 0;
            int sumR = 0;
            for(int j= 0; j < i;j++ ){
                sumL += nums[j];
            } 
            for(int j= i+1 ; j < n;j++ ){
                sumR += nums[j];
            }
            int diff = (sumL - sumR) ;
            if( diff < 0) {
                ans.push_back(-diff);
            }
            else{
                ans.push_back(diff);
            }            
        }
               return ans;
    }
};