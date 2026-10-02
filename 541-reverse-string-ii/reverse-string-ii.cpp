class Solution {
public:
    
    void reverse(string& s, int i, int j)
    {
        if(i >= j) return;
        s[i] = s[i] ^ s[j];
        s[j] = s[i] ^ s[j];
        s[i] = s[i] ^ s[j];
        reverse(s,i + 1, j - 1);
    }
    string reverseStr(string s, int k) {
        int i = 0;
        int j = k;
        while(j < s.size())
        {
            reverse(s,i,j-1);
            i += 2*k;
            j = i + k;
        }

        if(i < s.size())
        {
            reverse(s,i,s.size()-1);
        }

        return s;
    }
};