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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string s = "";
        while(temp != nullptr)
        {
            s += temp->val;
            temp = temp->next;
        }

        int n = s.size();
        int ans = 0;
        int j = 0;
        for(int i = n-1; i >= 0; i--)
        {
           if(s[i] != 0)
           {
             ans += pow(2,j);
           }
            j++;
        }

        return ans;

    }
};