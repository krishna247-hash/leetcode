class Solution {
public:
    vector<int> generateRow(int N)
    {
        long long ans = 1;

        vector<int>ansRow;

        ansRow.push_back(ans);

        for(int i = 1; i < N ; i++)
        {
            ans = ans * (N - i);
            ans = ans / i ;
            ansRow.push_back(ans);
        }
        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> temp;

        for (int i = 0; i < numRows; i++) {
            vector<int> Row = generateRow( i+1);
            
            temp.push_back(Row);
        }

        return temp;
    }
};