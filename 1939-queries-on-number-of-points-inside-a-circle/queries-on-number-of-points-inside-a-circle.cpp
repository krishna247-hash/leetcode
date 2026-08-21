class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> temp;
        for(auto it: queries){
            int cnt = 0;
            int x = it[0];
            int y = it[1];
            int R = it[2];

            for(auto coordinates : points){
                int X = coordinates[0] - x;
                int Y = coordinates[1] - y;

                if(((X * X) + (Y * Y)) <= (R * R)) cnt++;
            }
            temp.push_back(cnt);

        }
        return temp;
    }
};