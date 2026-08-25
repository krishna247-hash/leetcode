class Solution {
public:
    double minimumAverage(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        int low = 0;
        int high = n - 1;



        double ans = DBL_MAX;

        while(low < high) {

            double avg = (nums[low] + nums[high])/2.0;

            ans = min(ans, avg);



            low++;
            high--;

       
        }

        return ans;
    }
};