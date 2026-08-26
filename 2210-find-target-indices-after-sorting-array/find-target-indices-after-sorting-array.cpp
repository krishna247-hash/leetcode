class Solution {
public:

 int startingIndex(vector<int> &nums, int target){
            int index = nums.size();

            int low = 0;  int high = nums.size()-1;

            while(low <= high)
            {
                int mid = low + (high - low)/2;

                if(nums[mid] >= target){
                    index = mid;

                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            return index;

        }

        int endingIndex(vector<int> &nums, int target){
            int index = nums.size();

            int low = 0;  int high = nums.size()-1;

            while(low <= high)
            {
                int mid = low + (high - low)/2;

                if(nums[mid] > target){
                    index = mid;
                    
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }

           

            return index;

        }

    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

    

        vector<int> ans;

        for(int i = startingIndex(nums,target); i < endingIndex(nums,target); i++)
        {
            ans.push_back(i);
        }
      return ans;


    }
};