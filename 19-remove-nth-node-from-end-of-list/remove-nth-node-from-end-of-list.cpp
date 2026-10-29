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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;

        while(temp != NULL)
        {
            len = len + 1;
            temp = temp->next;
        }

        int k = len - n;

        if(len == n)
        {
            ListNode* node = head;
            head = head->next;
            delete node;
            return head;
        }

        // if(n == 1)
        // {
        //     temp = head;
        //     while(temp->next->next != NULL)
        //     {
        //         temp = temp->next;
        //     }

        //     temp->next = temp->next->next;
        //     return head;
        // }

        int cnt = 0;
        temp = head;
        while(cnt < k-1)
        {
            cnt++;
            temp = temp->next;
        }

        ListNode* node = temp->next;
        temp->next = temp->next->next;

        delete node;
        return head;

    }
};