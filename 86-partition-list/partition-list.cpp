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
    
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL) return head;
        vector<ListNode*> prev;
        ListNode* temp = head;
        while(temp != NULL)
        {
            if(temp->val < x) prev.push_back(temp);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL)
        {
            if(temp->val >= x) prev.push_back(temp);
            temp = temp->next;
        }

        ListNode* newHead = prev[0];
        for(int i = 1; i < prev.size(); i++)
         prev[i-1]->next = prev[i];
        
        prev[prev.size() - 1]->next = NULL;

        return newHead;
    }
};