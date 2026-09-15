class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n = position.size();
        int maxi = INT_MIN;
        int low = 1; 
        int high = position[n-1] - position[0];

        while(low <= high)
        {
            int mid = low + (high - low)/ 2;
            int st = position[0];
            int tempMaxi = INT_MIN;
            int cnt = m-1;
            for(int i = 1; i < n; i++)
            {
                if(position[i] - st >= mid)
                {
                    st = position[i];
                    cnt--;
                }
            }

            if(cnt <= 0) 
            {
                maxi = mid ;
                low = mid + 1;
            }
            else high = mid - 1;


        }

        return maxi;

    }
};