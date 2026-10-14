class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";

        if(num < (sum + 8)/9) return s;

        while(sum > 9)
        {
            s += '9';
            sum -= 9;
            num--;
        }
        s += sum + '0';
        num--;

        while(num--)
        s += '0';

        return s;
    }
};