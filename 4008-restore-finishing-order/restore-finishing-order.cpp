class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        int n1 = order.size();
        int n2 = friends.size();

        vector<int> temp;
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < n2; j++){
                if(order[i] == friends[j]) {
                    temp.push_back(order[i]);
                }
            }

        }
        return temp;
    }
};