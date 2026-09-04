class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        if(s.size() != t.size()) return false;

        for(auto it: s)
        {
            mp[it]++;
        }

        for(auto it: t)
        {
            if(mp[it] == 0) return false;
            mp[it]--;
        }
        return true;
    }
};