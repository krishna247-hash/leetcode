class Solution {
public:

    int total1s(vector<int> &nums){
        int low = 0; int high = nums.size() - 1;

        int ans = - 1;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(nums[mid] == 0){
                high = mid - 1;
            }
            else
            {
                ans = mid;

                low = mid + 1;
            }

        }

        return ans+1;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>> temp;
        vector<int> ans;


        int m = mat.size();
        int n = mat[0].size();

        for(int i = 0; i < m; i++)
        {
            int total1 = total1s(mat[i]);



            temp.push_back({total1,i});

        }

        sort(temp.begin(),temp.end());

        for(int i = 0; i < k; i++)
        {
            ans.push_back(temp[i].second);
        }

        return ans;
    }
};