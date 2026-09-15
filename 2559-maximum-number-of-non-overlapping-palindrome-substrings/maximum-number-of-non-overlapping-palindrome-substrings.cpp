class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        vector<vector<bool>> pal(n, vector<bool>(n, false));

        // Find all palindromes
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j] &&
                    (len <= 2 || pal[i + 1][j - 1])) {
                    pal[i][j] = true;
                }
            }
        }

        // DP
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {

            // Don't choose a palindrome ending at i
            if (i > 0)
                dp[i] = dp[i - 1];

            // Try every palindrome ending at i
            for (int j = 0; j <= i; j++) {

                if (i - j + 1 >= k && pal[j][i]) {

                    int previous = (j == 0 ? 0 : dp[j - 1]);

                    dp[i] = max(dp[i], previous + 1);
                }
            }
        }

        return dp[n - 1];
    }
};