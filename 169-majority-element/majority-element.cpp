class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        int cnt = 1;
        int maj = nums[0];

        for(int i = 1 ; i < n ;i++){
            if(cnt == 0){
                maj = nums[i];
            }
            if(nums[i]==maj){
                cnt++;
            }
            else if(nums[i]!=maj){
                cnt--;
            }
        }
       return maj;
    }
};