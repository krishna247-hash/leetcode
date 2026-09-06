class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(auto it: s)
        {
            if((it >= 97 && it <= 122) || (it >= 48 && it <= 57))
            {
                ans += it;
            }
            else if(it >= 65 && it <= 90)
            {
                ans += it - 'A' + 'a';
            }
        }

        int n = ans.size();
        int low = 0, high = n - 1;
        while(low < high)
        {
            if(ans[low++] != ans[high--]) return false;
        }

        return true;
    }
};