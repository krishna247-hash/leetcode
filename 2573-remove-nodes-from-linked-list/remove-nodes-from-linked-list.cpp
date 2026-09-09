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
    
ListNode* removeNodes(ListNode* head)
{
    ListNode* temp = head;
    if(temp == nullptr|| temp->next == nullptr) return head;

    ListNode* prev = nullptr;

    while(temp != nullptr)
    {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    temp = prev;

    int maxi = temp->val;
    ListNode* newhead = temp;
    ListNode* curr = newhead;
    temp = temp->next;
    while(temp != nullptr)
    {
        if(temp->val >= maxi)
        {
            maxi = temp->val;
            curr->next = temp;
            curr = curr->next;
        }
        temp = temp->next;
    }
    curr->next = nullptr;

    prev = NULL;
    temp = newhead;

    while(temp != nullptr)
    {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;

}
};