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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast == nullptr)
        {
            ListNode* temp = slow;
            ListNode* prev = nullptr;
            while(temp != nullptr)
            {
                ListNode* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }

            temp = prev;
            slow = head;

            while(temp != nullptr)
            {
                if(temp->val != slow->val) return false;
                temp = temp->next;
                slow = slow->next;
            }

            return true;
        }
         else if(fast->next == nullptr)
        {
            ListNode* temp = slow->next;
            ListNode* prev = nullptr;
            while(temp != nullptr)
            {
                ListNode* front = temp->next;
                temp->next = prev;
                prev = temp;
                temp = front;
            }

            temp = prev;
            slow = head;

            while(temp != nullptr)
            {
                if(temp->val != slow->val) return false;
                temp = temp->next;
                slow = slow->next;
            }

            return true;
        }

        return true;
    }
};