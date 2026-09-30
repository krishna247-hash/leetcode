class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans;
        for(int i = 0; i < pow(2,n); i++)
        {
            int x = i;
            x = (x >> 1);
            ans.push_back(start^(i^x));
        }
        return ans;
    }
};