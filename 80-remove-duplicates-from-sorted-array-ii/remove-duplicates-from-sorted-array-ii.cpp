class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
    int n = nums.size();
   int t = 0;
   for(int i = 0; i < n; i++){
    if(i < 2){
        nums[t++] = nums[i];
    }
    else if(nums[i] != nums[t-2]){
        nums[t++] = nums[i];
    }

   }

    return t;

    }
};