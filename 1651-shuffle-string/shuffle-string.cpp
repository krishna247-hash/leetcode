class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n = indices.size();
        unordered_map<int,char> mp;

        for(int i = 0; i < n; i++){
            mp[indices[i]] = s[i];
        }

        string ans = "";


        for(int i = 0 ; i < n; i++){
            ans +=mp[i];
        }

        return ans;

    }
};