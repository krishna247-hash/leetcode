class Solution {
public:
    void setZeroes(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        int col0 = 1;
         int row0 = 1;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(A[i][j] == 0){
                    if(j == 0) col0 = 0;
                    if(i == 0) row0 = 0;
                    A[i][0] = 0;
                    A[0][j] = 0;
                }
            }
        }

        for(int i = 1; i < row; i++){
            for(int j = 1; j < col; j++){
                if(A[i][0] == 0 || A[0][j] == 0){
                    A[i][j] = 0;
                }
            }
        }

       if(row0 == 0){

            for(int j = 0; j < col; j++){

                A[0][j] = 0;

            }

        }

         if(col0 == 0){
            for(int i = 1; i < row ; i++){
                A[i][0] = 0;
            }
        }
    }
};