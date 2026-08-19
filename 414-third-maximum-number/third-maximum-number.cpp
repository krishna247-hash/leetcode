class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int temp = 1;
        int maxi = nums.size()-1;
        sort(nums.begin(),nums.end());
        for(int i = nums.size()-2; i >=0; i--){
            if(nums[maxi] > nums[i]){
                maxi = i;
                temp++;
            }
            if(temp == 3) return nums[maxi];
            
        }
        return nums[nums.size()-1];


        
    }
};