class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int partition = 0 ;

        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                partition = i;
                break;
            }
        }
        for(int i = n-1; i >= partition ; i--)
        {
            if(nums[i] > nums[partition]){
                swap(nums[i],nums[partition++]);
                break;
            }
        }
       sort(nums.begin()+partition , nums.end());
        
    }
};