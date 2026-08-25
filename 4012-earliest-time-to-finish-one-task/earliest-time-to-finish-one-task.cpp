class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        
        int n = tasks.size();

        int mini = INT_MAX;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(auto it : tasks[i]){
                sum += it;
            }

            mini = min(mini,sum);

        }

        return mini;
    }
};