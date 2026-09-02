class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto it: nums)
        {
            if(it == 0) ans.push_back(it);
            else
            {
                int n = log10(it)+1;
                 vector<int> temp;
                while(it != 0)
                {                   
                    int digit = it % 10;
                    temp.insert(temp.begin(),digit);
                    it = it / 10;
                }
                for(auto x: temp)
                {
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};
