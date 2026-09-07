class Solution {
public:

    void validS(int i, string& s, int n, vector<string>& ans)
    {
        if(i == n)
        {
            int c = 0;
            for(int i = 1; i < n; i++)
            {
                if(s[i] == '0' && s[i-1] == '0')
                {
                    c = 1;
                }
            }

            if(c == 0) ans.push_back(s);
            return ;
        }

        s[i] = '0';
        validS(i+1,s,n,ans);
        s[i] = '1';
        validS(i+1,s,n,ans);

    }
    vector<string> validStrings(int n) {
       string s = "";
       for(int i = 0; i < n; i++)
       {
        s += '1';
       } 

       vector<string> ans;
       validS(0,s,n,ans);

       return ans;
    }
};