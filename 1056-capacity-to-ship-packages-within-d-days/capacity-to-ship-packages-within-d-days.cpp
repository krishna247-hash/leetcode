class Solution {
public:

    int totalSum(vector<int>& weights){
        int sum = 0;
        for(auto it: weights){
            sum += it;
        }

        return sum;
    }

    int countDays(vector<int>& weights, int capacity)
    {
        int sum = 0;  int days = 1;

        for(int i = 0; i < weights.size(); i++){
            if(sum + weights[i] > capacity){
                days++;
                sum = 0;
            }
            sum += weights[i];
        }

        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = totalSum(weights);
        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            int totalD = countDays(weights,mid);

            if(totalD <= days)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};