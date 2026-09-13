class Solution {
public:
    bool check(int row, int col,char val, vector<vector<char>>& board)
    {
         for(int i = 0; i < 9; i++)
         {
            if(board[row][i] == val) return false;
         }
         for(int i = 0; i < 9; i++)
         {
            if(board[i][col] == val) return false;
         }

         int rowStart = 3 * (row / 3), colStart = 3 * (col / 3);

         for(int i = 0; i < 3; i++)
         {
            for(int j= 0; j < 3; j++)
            {
                if(board[rowStart + i][colStart + j] == val) return false;
            }
         }

         return true;
    }

    bool solve(vector<vector<char>>& board)
    {
        
        for(int i = 0; i < 9; i++)
        {
            
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    for(int ch = 1; ch <= 9; ch++)
                    {
                        char val = ch + '0';
                        if(check(i,j,ch +'0',board))
                        {
                            board[i][j] = val;
                            if(solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};