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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        int cnt = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }

        if(k == 0 ||k % cnt == 0) return head;
        k = k % cnt;

        k = cnt - k;

        cnt = 1;
        temp = head;

        while(cnt < k)
        {
            temp = temp->next;
            cnt++;
        }

        ListNode* newhead = temp->next;
        temp->next = nullptr;
        temp = newhead;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = head;


     return newhead;
    }
};