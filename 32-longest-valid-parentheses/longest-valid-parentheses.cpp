class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int ans = 0;

        // Left -> Right
        for(auto it : s)
        {
            if(it == '(')
                left++;
            else
                right++;

            if(left < right)
            {
                left = 0;
                right = 0;
            }

            if(left == right)
            {
                ans = max(ans, right * 2);
            }
        }

        left = 0;
        right = 0;

        // Right -> Left
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == '(')
                left++;
            else
                right++;

            if(right < left)
            {
                left = 0;
                right = 0;
            }

            if(left == right)
            {
                ans = max(ans, left * 2);
            }
        }

        return ans;
    }
};