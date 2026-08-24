class Solution {
public:
    int countGoodTriplets(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        int cnt = 0;

        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    int e1 = nums[i] - nums[j];
                    int e2 = nums[j] - nums[k];
                    int e3 = nums[i] - nums[k];

                    if(abs(e1) <= a && abs(e2) <= b && abs(e3) <= c){
                        cnt++;
                    }


                }
            }
        }

        return cnt;
    }
};