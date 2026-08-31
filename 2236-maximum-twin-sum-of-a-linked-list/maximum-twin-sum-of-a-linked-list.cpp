/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    vector<int> LL2Array(ListNode* head)
    {
        ListNode* temp = head;
        vector<int> arr;
        while(temp != nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        return arr;
    }
    int pairSum(ListNode* head) {
        vector<int> temp = LL2Array(head);
        int n = temp.size()-1;

        int i = 0;  int j = n;
        int sum = INT_MIN;
        while(i < j)
        {
            sum = max(sum , temp[i++]+temp[j--]);
        }
        return sum;
    }
};