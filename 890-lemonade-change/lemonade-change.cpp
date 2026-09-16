class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        map<int,int,greater<int>> mp;
         int five = 0;
         int ten = 0;
         int twenty = 0;

        for(int i = 0; i < n; i++)
        {
            int s = bills[i];
           if(bills[i] == 5)
           {
            five++;
           }
           else if(bills[i] == 10 )
           {
            if(five > 0)
            {
                five--;
                ten++;
            }
            else return false;
           }
           else if(bills[i] == 20)
           {
            if(ten > 0 && five > 0)
            {
                twenty++;
                five--;
                ten--;
            }
            else if(five > 2)
            {
                five -= 3;
                twenty++;
            }
            else return false;
           }
        }
        return true;
    }
};