class Solution {
public:
    void MS(vector<int>&nums , int low,int mid,int high)
    {
        int left = low;  int right = mid+1;
        vector<int> temp;
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left++]);
            }
            else
            {
                temp.push_back(nums[right++]);
            }
        }
        while(left <= mid)
        {
            temp.push_back(nums[left++]);
        }
        while(right <= high)
        {
            temp.push_back(nums[right++]);
        }

        int j = 0;
        for(int i = low; i <= high; i++)
        {
            nums[i] = temp[j++];
        }
    }

    void mergeSort(vector<int>& nums,int low,int high)
    {
        if(low == high) return;
        int mid = low + (high - low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        MS(nums,low,mid,high);
    }

    void increaseSort(vector<int>& nums)
    {
        int n = nums.size();
        mergeSort(nums,0,n-1);
    }

    void decreaseSort(vector<int>& nums)
    {
        int n = nums.size();
        mergeSort(nums,0,n-1);

        int i = 0;  int j = n - 1;

        while(i < j)
        {
            swap(nums[i++],nums[j--]);
        }
    }


    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        

        for(int i = 0; i < n; i++)
        {
            vector<int> temp;
            int row = i; int col = 0;
            while(row < n && col < n)
            {
                temp.push_back(grid[row++][col++]);
            }
            decreaseSort(temp);
            row = i;  col = 0; int t = 0;
            while(row < n && col < n)
            {
                grid[row++][col++] = temp[t++];
            }
        }

        for(int j = 1; j < n; j++)
        {
            int col = j; int row = 0;
            vector<int> temp;
            while(col < n && row < n)
            {
                temp.push_back(grid[row++][col++]);
            }

            increaseSort(temp);
              col = j;  row = 0; int t = 0;
             while(col < n && row < n)
            {
                grid[row++][col++] = temp[t++];
            }

        }

        return grid;
    }
};