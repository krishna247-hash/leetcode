class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    vector<int>temp;
    for(int i = 1; i < n; i++)
    {
    if(nums[i] != nums[i-1]+1){
        int k = nums[i-1]+1;
        while( k < nums[i])
        {
            temp.push_back(k);
            k++;
        }
    }    
    }
    return temp;
    }
};