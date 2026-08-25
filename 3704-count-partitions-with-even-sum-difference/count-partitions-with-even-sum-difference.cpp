class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;

        int e = 0; int cnt = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        for(int i = 0; i < n-1; i++){
            e += nums[i];
             sum = sum - nums[i];

            int t = sum - e;

            if(t % 2 == 0){
                cnt++;
            }

           
        }

        return cnt;
    }
};