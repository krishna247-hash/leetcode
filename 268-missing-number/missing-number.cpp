class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
       int XOR1 = 0;
       for(int i = 1 ; i <= n ; i++){
         XOR1 = XOR1 ^ i;
         XOR1 = XOR1 ^ nums[i-1];
        
       

       }
       return XOR1;
       
       
    }
};