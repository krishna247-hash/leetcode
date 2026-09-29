class Solution {
public:
    
    void solve(vector<int>& digits, set<int>& st, vector<int>& temp)
    {
        if(temp.size() == 3)
        {
            if(temp[0] != 0 && !(temp[2] & 1))
            {
                int sum = 0;
                for(auto it: temp)
                {
                    sum = sum * 10 + it;
                }
                st.insert(sum);
            }
            return;
        }

        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] >= 0)
            {
                temp.push_back(digits[i]);
                int x = digits[i];
                digits[i] = -999;
                solve(digits,st,temp);
                temp.pop_back();
                digits[i] = x;
            }
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        vector<int> ans;
        vector<int> temp;
        solve(digits,st,temp);

        for(auto it: st)
        {
            ans.push_back(it);
        }
        sort(ans.begin(),ans.end());

        return ans;
    }
};