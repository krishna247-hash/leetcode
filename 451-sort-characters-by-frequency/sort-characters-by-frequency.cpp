class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto it: s)
        {
            mp[it]++;
        }
        vector<pair<int,char>> temp;
        for(auto it: mp)
        {
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        s = "";
        for(auto it: temp)
        {
            for(int i = 0; i < it.first; i++)
            {
               s += it.second; 
            }
            
        }
        return s;
    }
};