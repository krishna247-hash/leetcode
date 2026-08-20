class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> temp;
        int cnt = 0;
        for(int i = 0; i < n;i++){
            if(nums[i] < pivot){
                temp.push_back(nums[i]);
            }
            if(nums[i] == pivot){
                cnt++;

            }


        }
        while(cnt--){
            temp.push_back(pivot);
        }
        for(int i = 0; i < n;i++){
            if(nums[i] > pivot){
                temp.push_back(nums[i]);
            }
           

        }
        return temp;
    }
};