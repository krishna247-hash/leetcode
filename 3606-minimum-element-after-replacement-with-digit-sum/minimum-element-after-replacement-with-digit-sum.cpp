class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini = INT_MAX;
        for(auto it: nums){
            int s = 0;
            while(it > 0){
                s += (it%10);
               it = it / 10;
            }
            mini = min(mini,s);

        }
        return mini;                 
    }
};