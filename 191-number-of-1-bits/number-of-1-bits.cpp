class Solution {
public:
    int hammingWeight(int n) {

        // using bit manipulation
        int cnt = 0;
        while(n != 0)
        {
            int digit = n & 1;
            if(digit) cnt++;
            n = n >> 1;
        }

        return cnt;
    }
};