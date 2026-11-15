class Solution {
public:
    int MOD = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0;
        int even = 1; 
        int curr = 0;
        int cnt = 0;

        for (auto x : arr) {
            curr = (curr + x) & 1; 
            
            if (curr) {
                cnt = (cnt + even) % MOD;
                odd++;
            } else {
                cnt = (cnt + odd) % MOD;
                even++;
            }
        }
        return cnt;
    }
};

// TC = O(n)
// SC = O(1)












