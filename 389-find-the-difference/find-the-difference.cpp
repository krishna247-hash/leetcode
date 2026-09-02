class Solution {
public:
    char findTheDifference(string s, string t) {
       char XOR =0;
       for(auto it: s)
       {
        XOR = XOR ^ it;
       }
       for(auto it: t)
       {
        XOR = XOR ^ it;
       }

        return XOR;
    }
};