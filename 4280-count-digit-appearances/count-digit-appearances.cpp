class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;

        for(auto it: nums){
            while(it != 0){
                int d = it % 10;

                it = it / 10;

                if(d == digit) cnt++;


            }
        }

        return cnt;
    }
};