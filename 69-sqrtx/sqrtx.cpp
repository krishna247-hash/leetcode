class Solution {
public:
    int mySqrt(int x) {
        int low = 0; int high = x;
        int ans = x;

        while(low <= high)
        {
            long long mid = low + (high - low)/2;

            long long e = mid * mid;

            if(e <= x)
            {
                ans = mid;

                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};