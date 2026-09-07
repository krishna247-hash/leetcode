class Solution {
public:
    long long M = 1e9+7;
    int power(int x, long long n)
    {
        int ans = 1;
        while(n > 0)
        {
            if(n % 2 != 0)
            {
                ans = ((ans % M) * (x % M))%M;
                n--;
            }
            else
            {
                x = ((x % M) * (x % M))%M;
                n = n / 2;
            }
        }
        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1)/2;
        long long odd = n / 2;

        return ((power(5,even) % M)* (power(4 , odd) % M)) % M;
    }
};