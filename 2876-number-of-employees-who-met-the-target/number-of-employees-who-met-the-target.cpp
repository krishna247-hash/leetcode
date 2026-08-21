class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int temp = 0;
        for(auto it: hours){
            if(it >= target) temp++;

        }
        return temp;
    }
};