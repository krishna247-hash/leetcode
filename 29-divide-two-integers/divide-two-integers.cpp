class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = 0;
        if(dividend < 0 && divisor > 0) sign = 1;
        if(dividend > 0 && divisor < 0) sign = 1;

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        if(a < b) return 0;

        long long ans = 0;
        while(a >= b)
        {
            long long cnt = 1;
            long long m = b;
            while(a >= m << 1)
            {
                m = m << 1;
                cnt = cnt + cnt;
            }
            ans += cnt; 
            a = a - m;
        }
        if(sign) ans = -ans;
        if(ans >= INT_MAX) return INT_MAX;
        if(ans <= INT_MIN) return INT_MIN;
        

        return ans;
        
    }
};