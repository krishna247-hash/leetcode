class Solution {

public:

    double myPow(double x, int n) {

        long long t = n;

        if(t < 0)

        {

            x = 1 / x;

            t = -t;

        }

        if(t == 0)

            return 1.0;

        double ans = myPow(x, t / 2);

        if(t % 2 == 0)

            return ans * ans;

        return x * ans * ans;

    }

};