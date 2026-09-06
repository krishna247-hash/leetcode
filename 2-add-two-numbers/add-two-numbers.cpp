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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int digit = 0;
        ListNode* newnode = new ListNode(0);
        ListNode* temp = newnode;
        ListNode* temp1 = l1; 
        ListNode* temp2 = l2;

        while(temp1 != nullptr && temp2 != nullptr)
        {
            int sum = temp1->val + temp2->val + carry;
            int value = sum % 10;
            ListNode* front = new ListNode(value);
            sum = sum / 10;
            carry = sum;

            temp->next = front;
            temp = front;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while(temp1 != nullptr)
        {
            int sum = temp1->val + carry;
            int value = sum % 10;
            ListNode* front = new ListNode(value);
            sum = sum / 10;
            carry = sum;
            temp->next = front;
            temp = front;
            temp1 = temp1->next;

        }

        while(temp2 != nullptr)
        {
            int sum = temp2->val + carry;
            int value = sum % 10;
            ListNode* front = new ListNode(value);
            sum = sum / 10;
            carry = sum;
            temp->next = front;
            temp = front;
            temp2 = temp2->next;
        }

        if(carry != 0)
        {
            ListNode* front = new ListNode(carry);
            temp->next = front;
            temp = front;
            carry = 0;
        }

        return newnode->next;
    }
};