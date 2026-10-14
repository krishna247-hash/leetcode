#define ll long long
#define pb push_back

class Solution {
public:
    void solve(int i, string& num, ll target, string& temp, vector<string>& ans, ll val, ll prev)
    {
        if(i == num.size())
        {
            if(val == target) ans.pb(temp);
            return;
        }

        ll x = 0;

        for(int j = i; j < num.size(); j++)
        {
            if(j > i && num[i] == '0') break;

            x = x*10 + (num[j]-'0');

            string s = num.substr(i,j-i+1);
            int sz = temp.size();

            if(i == 0)
            {
                temp += s;
                solve(j+1,num,target,temp,ans,x,x);
                temp.resize(sz);
            }
            else
            {
                temp += '+' + s;
                solve(j+1,num,target,temp,ans,val+x,x);
                temp.resize(sz);

                temp += '-' + s;
                solve(j+1,num,target,temp,ans,val-x,-x);
                temp.resize(sz);

                temp += '*' + s;
                solve(j+1,num,target,temp,ans,val-prev+prev*x,prev*x);
                temp.resize(sz);
            }

            if(x > LLONG_MAX / 10) break;
        }
    }

    vector<string> addOperators(string num, int target)
    {
        vector<string> ans;
        string temp = "";

        solve(0,num,target,temp,ans,0,0);

        return ans;
    }
};