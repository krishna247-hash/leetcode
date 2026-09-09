class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        // 4 to 6 digit numbers -> 1 comma
        if(n >= 1000)
            ans += n - 999;

        // 7 to 9 digit numbers -> 2 commas
        if(n >= 1000000)
            ans += n - 999999;

        // 10 to 12 digit numbers -> 3 commas
        if(n >= 1000000000)
            ans += n - 999999999;

        // 13 to 15 digit numbers -> 4 commas
        if(n >= 1000000000000LL)
            ans += n - 999999999999LL;

        // 16 to 18 digit numbers -> 5 commas
        if(n >= 1000000000000000LL)
            ans += n - 999999999999999LL;

        return ans;
    }
};