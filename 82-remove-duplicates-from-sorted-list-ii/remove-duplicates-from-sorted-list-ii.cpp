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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* current = head;
        ListNode* dummy = new ListNode(0,head);

        ListNode* prev = dummy;
        ListNode* front = current->next;
        while(current != nullptr)
        {
            if(current->next != nullptr && current->val == current->next->val )
            {
                int val = current->val;

                while(current != nullptr && current->val == val)

                {

                    current = current->next;

                }

                prev->next = current;
            }
            else

            {

                prev = current;

                current = current->next;

            }
           
        }
        return dummy->next;
    }
};