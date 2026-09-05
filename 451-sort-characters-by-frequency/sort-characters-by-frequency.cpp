class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto it: s)
        {
            mp[it]++;
        }
        vector<pair<int,char>> temp;
        for(auto it: s)
        {
            temp.push_back({mp[it],it});
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        s = "";
        for(auto it: temp)
        {
            s += it.second;
        }
        return s;
    }
};