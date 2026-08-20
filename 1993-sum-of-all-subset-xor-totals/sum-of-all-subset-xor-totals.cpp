class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
       
        vector<vector<int>> nigga = subsets(nums);
        int sum = 0;
        for(auto it: nigga){ 
            int XOR = 0;
		for(auto x: it){
			XOR = XOR ^ x;
		}
        sum = sum + XOR;
        }

        return sum;
		
	

        
    }

    vector<vector<int>> subsets(vector<int>& nums){
	vector<int> v;
	int n = nums.size();
	vector<vector<int>>ans;

	ans.push_back({});
	for(int i = 0; i < n ; i++){
		int size = ans.size();

		for(int j = 0; j < size; j++){
			vector<int> temp = ans[j];
			temp.push_back(nums[i]);
			ans.push_back(temp);

		}

	}
	return ans;

   }





};