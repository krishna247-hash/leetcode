class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0,high = matrix[0].size()-1;

        while(low < matrix.size() && high >= 0){
            if(matrix[low][high] == target) return true;
            else if(matrix[low][high] < target) low++;
            else high--;
        }

        return false;
    }
};