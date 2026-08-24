class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int sum = 0;
        int digitSum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int t = nums[i];
            sum += t;

            while(t > 0)
            {
                digitSum += t%10;

                t /= 10;

            }
        }

        return abs(sum - digitSum);

    }
};