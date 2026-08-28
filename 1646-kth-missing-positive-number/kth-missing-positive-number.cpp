class Solution {
public:

    int totalMissing(vector<int>& arr, int idx)
    {
        return arr[idx] - idx - 1;
    }

    int findKthPositive(vector<int>& arr, int k)
    {
        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            int missing = totalMissing(arr, mid);

            if(missing < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return low + k;
    }
};