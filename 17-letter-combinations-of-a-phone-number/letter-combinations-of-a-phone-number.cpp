class Solution {
public:
    
    void combinations(int idx,int n, string& temp, string& digits, vector<string>& mp, vector<string>& ans)
    {
        if(idx == n)
        {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < mp[digits[idx] - '0'].size(); i++)
        {
            temp.push_back(mp[digits[idx] - '0'][i]);
            combinations(idx + 1,n,temp,digits,mp,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mp(10);
        mp[1] ="";
        mp[0] = "";
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string temp = "";

        int n = digits.size();
        vector<string> ans;
        combinations(0,digits.size(),temp,digits,mp,ans);
        return ans;
    }
};