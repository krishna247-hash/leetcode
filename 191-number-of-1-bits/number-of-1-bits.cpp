class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0)
        {
            int digit = n % 2;
            if(digit) cnt++;
            n = n / 2;
        }

        return cnt;
    }
};