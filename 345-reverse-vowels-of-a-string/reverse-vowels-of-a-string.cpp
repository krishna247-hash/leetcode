class Solution {
public:
    int right(int j, string s, unordered_map<char,int> mp)
    {
        while(j >= 0 && mp[s[j]] != 1)
        j--;

        return j;
    }
    int left(int i,string s,unordered_map<char,int> mp)
    {
        while(i < s.size() && mp[s[i]] != 1)
        i++;

        return i;
    }
    string reverseVowels(string s) {
        unordered_map<char,int> mp ={{'a',1},{'e',1},{'i',1},{'o',1},{'u',1},{'A',1},{'E',1},{'I',1},{'O',1},{'U',1}};
        int i = left(0,s,mp);
        int j = right(s.size()-1,s,mp);

        while(i < j)
        {
            s[i] = s[i] ^ s[j];
            s[j] = s[i] ^ s[j];
            s[i] = s[i] ^ s[j];

            i = left(i+1,s,mp);
            j = right(j-1,s,mp);
        }

        return s;
    }
};