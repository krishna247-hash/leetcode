class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> arr;
        vector<vector<int>> ans;
        for(auto it : intervals)
        arr.push_back({it[0],it[1]});

        sort(arr.begin(),arr.end());

        int i = 0;
        while(i < arr.size())
        {
            int st = arr[i].first;
            int end = arr[i].second;
            bool flag = 0;
            while(i < arr.size() && end >= arr[i].first)
            {
                end =max(end,arr[i].second);
                i++;
                flag = 1;
            }
            if(flag)i--;
            i++;
            ans.push_back({st,end});
        }

        return ans;
    }
};