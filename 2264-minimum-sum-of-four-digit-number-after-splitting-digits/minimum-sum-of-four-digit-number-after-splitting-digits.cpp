class Solution {
public:
    int minimumSum(int num) {
        int mini = INT_MAX;
        
       vector<int>nums;

       while(num != 0){
        nums.push_back(num % 10);

        num /= 10;
       }

       sort(nums.begin(),nums.end());

       int e1 = nums[0]*10 + nums[3];
      int e2 = nums[1]*10 + nums[2];

       return e1+e2;
    }
};