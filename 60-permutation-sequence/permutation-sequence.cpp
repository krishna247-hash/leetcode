class Solution {
public:
     
     int cnt = 0; bool found = 0;
    void combinations(vector<int>& temp, int n, vector<int>& mp , int k, string& ans)
    {
        if(temp.size() == n)
        {
            cnt++;
            if(cnt == k) {

                for(auto it : temp)
                ans += it + '0';
                found = 1;
            }
            return;
        } 

        for(int i = 1; i <= n; i++)
        {
            if(mp[i] == 0)
            {
                mp[i] = 1;
                temp.push_back(i);
                combinations(temp,n,mp,k,ans);
                if(found == 1) break;
                mp[i] = 0;
                temp.pop_back();

            }
        }
    }
    string getPermutation(int n, int k) {
        vector<int> mp(n+1,0);
        string ans;
        vector<int> temp;
        combinations(temp,n,mp,k,ans);
      return ans;

    }
};