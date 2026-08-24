class Solution {
public:
    long long nCr(int n, int r) {
        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
        }

        return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> temp;

        for (int i = 0; i < numRows; i++) {
            vector<int> ans;

            for (int j = 0; j <= i; j++) {
                ans.push_back(nCr(i, j));
            }

            temp.push_back(ans);
        }

        return temp;
    }
};