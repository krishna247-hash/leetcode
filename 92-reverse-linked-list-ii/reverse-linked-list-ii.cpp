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
    ListNode* reverseLL(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(temp != NULL)
        {
            ListNode* node = temp->next;
            temp->next = prev;
            prev = temp;
            temp = node;
        }

        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
       
        if(left == right) return head;
        ListNode* newhead = new ListNode(-1);
        newhead->next = head;
        ListNode* leftSt = newhead;
        ListNode* rightSt = NULL;
        ListNode* temp = newhead;
        for(int i = 1; temp != NULL ; i++)
        {
            if(i == left) leftSt = temp;
            if(i == right) rightSt = temp;
            temp = temp->next;
        }
        rightSt = rightSt->next;
        ListNode* rightHead = rightSt->next;
        rightSt->next = NULL;
        temp = reverseLL(leftSt->next);
        leftSt->next = temp;
        while(temp->next != NULL) temp = temp->next;
        temp->next = rightHead;

        return newhead->next;
    }
};