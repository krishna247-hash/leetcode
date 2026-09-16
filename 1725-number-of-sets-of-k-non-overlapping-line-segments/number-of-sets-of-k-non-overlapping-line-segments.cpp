class Solution {
public:
    long long MOD = 1e9 + 7;

    long long power(long long a, long long b)
    {
        long long ans = 1;

        while(b > 0)
        {
            if(b & 1)
                ans = ans * a % MOD;

            a = a * a % MOD;
            b /= 2;
        }

        return ans;
    }

    long long C(int n, int r)
    {
        if(r < 0 || r > n)
            return 0;

        long long ans = 1;

        for(int i = 1; i <= r; i++)
        {
            ans = ans * (n - i + 1) % MOD;
            ans = ans * power(i, MOD - 2) % MOD;
        }

        return ans;
    }

    int numberOfSets(int n, int k)
    {
        return C(n + k - 1, 2 * k);
    }
};