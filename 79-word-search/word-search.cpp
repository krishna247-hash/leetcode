class Solution {
public:
    int m, n;

    int dr[4] = {0, 1, -1, 0};
    int dc[4] = {1, 0, 0, -1};

    bool find(int i, int j, int idx,
              vector<vector<char>>& board, string& word)
    {
        if(idx == word.size())
            return true;

        if(i < 0 || j < 0 || i >= m || j >= n ||
           board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$';

        for(int k = 0; k < 4; k++)
        {
            int ni = i + dr[k];
            int nj = j + dc[k];

            if(find(ni, nj, idx + 1, board, word))
            {
                board[i][j] = temp;
                return true;
            }
        }

        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        m = board.size();
        n = board[0].size();

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(board[i][j] == word[0] &&
                   find(i, j, 0, board, word))
                {
                    return true;
                }
            }
        }

        return false;
    }
};