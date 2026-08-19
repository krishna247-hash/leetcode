class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int> temp;

        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;

        while(i < n1 && j < n2){
            if(nums1[i] == nums2[j]){
                
                if(temp.size() == 0){
                    temp.push_back(nums1[i]);
                    
                }
                else {

                    if(temp.back() != nums1[i]){
                        temp.push_back(nums1[i]);
                    }
                }
                i++;
                j++;

            }

            else if(nums1[i] < nums2[j]){
                i++;
            }
            else {
                j++;
            }
            
        }
        return temp;





    }
};