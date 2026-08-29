class Solution {
public:

  void MS(vector<int>& nums,int low,int mid,int high)
  {
    vector<int> temp;
    int left = low;    int right = mid+1;

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
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums,0,n-1);
        return nums;
    }
};