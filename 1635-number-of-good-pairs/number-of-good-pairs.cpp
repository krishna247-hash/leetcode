class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,int> mp;
        for(int i = 0; i < n;i++){
            mp[nums[i]]++;

        }
        int sum = 0;
        for(auto it : mp ){

            sum = sum + nCr(it.second,2);

        }
        return sum;

    }

    long long nCr(int n, int r) {
    long long ans = 1;

    for (int i = 0; i < r; i++) {
        ans = ans * (n - i) / (i + 1);
    }

    return ans;
}
};