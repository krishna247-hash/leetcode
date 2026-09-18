class Solution {
public:

    int count(int low, int mid, int high, vector<int>& nums)
    {
        int j = mid + 1;
        int cnt = 0;

        for(int i = low; i <= mid; i++)
        {
            while(j <= high && (long long)nums[i] > 2LL * nums[j])
            {
                j++;
            }

            cnt += j - (mid + 1);
        }

        return cnt;
    }

    void Merge(int low, int mid, int high, vector<int>& nums)
    {
        int left = low;
        int right = mid + 1;

        vector<int> temp;

        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high)
        {
            temp.push_back(nums[right]);
            right++;
        }

        int j = 0;

        for(int i = low; i <= high; i++)
        {
            nums[i] = temp[j++];
        }
    }

    int MergeSort(int low, int high, vector<int>& nums)
    {
        if(low >= high) return 0;

        int mid = low + (high - low) / 2;

        int cnt = 0;

        cnt += MergeSort(low, mid, nums);
        cnt += MergeSort(mid + 1, high, nums);

        cnt += count(low, mid, high, nums);

        Merge(low, mid, high, nums);

        return cnt;
    }

    int reversePairs(vector<int>& nums)
    {
        int n = nums.size();

        return MergeSort(0, n - 1, nums);
    }
};