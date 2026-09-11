class Solution {
public:

    void permutations(vector<int>& digits, vector<int>& used,
                      int num, int count, int& ans)
    {
        // 3 digits formed
        if(count == 3)
        {
            ans++;
            return;
        }

        for(int i = 0; i < digits.size(); i++)
        {
            if(used[i]) continue;

            // First digit cannot be 0
            if(count == 0 && digits[i] == 0)
                continue;

            // Last digit must be even
            if(count == 2 && digits[i] % 2 != 0)
                continue;

            // Skip duplicate digits at same recursion level
            if(i > 0 && digits[i] == digits[i - 1] && !used[i - 1])
                continue;

            used[i] = 1;

            permutations(
                digits,
                used,
                num * 10 + digits[i],
                count + 1,
                ans
            );

            used[i] = 0;
        }
    }

    int totalNumbers(vector<int>& digits)
    {
        sort(digits.begin(), digits.end());

        vector<int> used(digits.size(), 0);

        int ans = 0;

        permutations(digits, used, 0, 0, ans);

        return ans;
    }
};