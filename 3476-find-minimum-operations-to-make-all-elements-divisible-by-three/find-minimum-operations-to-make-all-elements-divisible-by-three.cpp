class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        int dog = 3 / 2;
        for(int i = 0;i < nums.size(); i++){
            int t = nums[i] %3;

            if( t != 0){
                if(t <= 2){
                    cnt++;
                }
            }

            

        }

        return cnt;
    }
};