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
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr = head;
        if(curr == nullptr || curr->next == nullptr)
        return head;

        vector<int> temp;
        while(curr != NULL)
        {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        vector<int> ans;
        int maxi = INT_MIN;
        for(int i = temp.size()-1; i >= 0; i--)
        {           
            if(temp[i] >= maxi)
            {
                ans.push_back(temp[i]);
            }
            maxi = max(maxi,temp[i]);
        }

        reverse(ans.begin(),ans.end());
        if(ans.size() == 0) return nullptr;
        ListNode* newhead = new ListNode(ans[0]);
        ListNode* templl = newhead;
        for(int i = 1; i < ans.size(); i++)
        {
            ListNode* newnode = new ListNode(ans[i]);
            templl->next = newnode;
            templl = templl->next;
        }
        return newhead;
    }
};