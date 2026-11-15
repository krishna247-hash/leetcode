class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long odd = 0;
        long long even = 1; 
        long long curr = 0;
        long long cnt = 0;
        long long MOD = 1e9 + 7;

        for (int x : arr) {
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












