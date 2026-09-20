class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int mini = INT_MAX;
        int secondMini = INT_MAX;

        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] <= mini)
            {
                secondMini = mini;
                mini = prices[i];
            }
            else if(prices[i] < secondMini)
            {
                secondMini = prices[i];
            }
        }

        int cost = mini + secondMini;

        if(cost > money)
            return money;

        return money - cost;
    }
};