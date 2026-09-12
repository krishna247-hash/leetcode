class Solution {
public:
    vector<int> grayCode(int n) {
        n = pow(2,n) - 1;
        vector<int> arr;
        arr.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            int gray = i ^ (i >> 1);
            arr.push_back(gray);
        }
        return arr;
    }
};