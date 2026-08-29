class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        string ans = "";
        int i = 0;

        while(i < n && s[i] == ' ')
            i++;

        if(i < n && (s[i] == '-' || s[i] == '+')) {
            ans += s[i];
            i++;
        }

        for(; i < n; i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                ans += s[i];
            }
            else
            {
                break;
            }
        }

        if(ans.empty() || ans == "+" || ans == "-")
            return 0;

        int neg = 0;
        int l = 0;

        if(ans[l] == '-') {
            neg = 1;
            l = 1;
        }
        else if(ans[l] == '+') {
            l = 1;
        }

        long long num = 0;

        for(; l < ans.size(); l++)
        {
            num = num * 10 + (ans[l] - '0');

            if(!neg && num > INT_MAX)
                return INT_MAX;

            if(neg && -num < INT_MIN)
                return INT_MIN;
        }

        if(neg)
            num = -num;

        return num;
    }
};