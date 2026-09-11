class Solution {
public:
    
    bool check(int row,int col, vector<vector<char>>& board)
    {
        char c = board[row][col];
        for(int i = 0; i < 9; i++)
        {
            if(i != row && board[i][col] == c) return false;
        }

         for(int i = 0; i < 9; i++)
        {
            if(i != col && board[row][i] == c) return false;
        }

        int startRow = 3*(row/3), startCol = 3*(col/3);
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if((startRow + i != row && startCol + j != col) && board[startRow + i][startCol + j] == c) return false;
            }
        }

        return true;
    }
    bool solveSudoku( vector<vector<char>>& board)
    {
        for(int row = 0; row < 9; row++)
        {
        for(int col = 0; col < 9; col++)
        {
            if(board[row][col] != '.')
            {
                if(!check(row,col,board)) return false;
            }
        }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solveSudoku(board);
    }
};