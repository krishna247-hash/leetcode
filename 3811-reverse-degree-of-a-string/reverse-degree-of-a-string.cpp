class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        int pos = 1;
        for(auto it: s)
        {
            sum += (123 - (int)it) * pos;
            pos++;
        }
        return sum;
    }
};