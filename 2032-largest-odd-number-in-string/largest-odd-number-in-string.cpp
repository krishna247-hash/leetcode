class Solution {
public:
    string largestOddNumber(string num) {
        int last = -1;
        int n = num.size();
        for(int i = n - 1; i >= 0; i--)
        {
            if((num[i] - '0' ) % 2 != 0) {
                last = i;
                break;
            }
        }
        return num.substr(0,last+1);
    }
};