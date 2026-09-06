class Solution {
public:    
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
       int n = grid.size();
       unordered_map<int,int> mp;
       vector<int> ans;
       int repeat = 0;
       
       for(auto it: grid)
       {
        for(auto x: it)
        {
            if(mp[x] != 0)
            {
                repeat = x;
                break;
            }
            else
            mp[x]++;
        }
        if(repeat != 0) break;
       }


       int XOR = repeat;
       for(int i = 0; i <= n*n; i++)
       {
        XOR = XOR ^ i;
       }

       for(auto it: grid)
       {
        for(auto x: it)
        {
            if(x != repeat)
            {
                XOR = XOR ^ x;
            }
        }
       }




       ans.push_back(repeat);
       ans.push_back(XOR);
       return ans;

       


    }
};