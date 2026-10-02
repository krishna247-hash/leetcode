using ll = int;
class Solution {
public:
    void reverseString(vector<char>& s) {
        ll i = 0;
        ll j = s.size()-1;
        while(i < j)
        {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;

            i++;
            j--;
        }
    }
};