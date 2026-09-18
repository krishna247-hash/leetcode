class Solution {
public:
    int largestInteger(int n, int s) {
        if(n*9 < s) return -1;
        if(n == 1) return s;
        int cnt = 1;
        int ans = 0;
        while(s >= 9)
        {
            ans = ans* 10 + 9;
            s = s - 9;
            cnt++;
        }
        
        if(cnt <= n)
        {ans = ans* 10 + s;
        for(;cnt < n; cnt++)
        {
            ans = ans* 10;

        }}
        return ans;
    }
};