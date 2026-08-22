class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int m = score.size();
        int n = score[0].size();

        for(int j = 0; j < m-1; j++){
            int maxi = j;
            for(int i = j; i < m; i++){
                
                if(score[i][k] > score[maxi][k]){
                    maxi = i;
                }

            }

           
                swap(score[maxi],score[j]);
            

        }
        return score;
    }
};