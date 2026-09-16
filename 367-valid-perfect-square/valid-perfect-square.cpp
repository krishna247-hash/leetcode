class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1;
        int high = num;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            long long sq = 1ll*mid * mid;
            if(sq == num) return mid;
            else if(sq < num) low = mid + 1;
            else high = mid - 1;
        }

        return 0;
    }
};