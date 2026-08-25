class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        
        int n = tasks.size();

        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            

            mini = min(mini,tasks[i][0]+tasks[i][1]);

        }

        return mini;
    }
};