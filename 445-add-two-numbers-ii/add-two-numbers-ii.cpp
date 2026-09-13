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
    ListNode* reverseLL(ListNode* l1)
    {
        ListNode* temp = l1;
        ListNode* prev = nullptr;
        while(temp != nullptr)
        {
            ListNode* newNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newNode;
        }
        return prev;
    }

    ListNode* AddLL(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(0);
        ListNode* temp = head;
        int carry = 0;
        while(l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr)
        {
            int sum = l1->val + carry;
            carry = (sum)/10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = newNode;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            int sum = l2->val + carry;
            carry = (sum)/10;
            sum = sum % 10;
            ListNode* newNode = new ListNode(sum);
            temp->next = newNode;
            temp = newNode;
            l2 = l2->next;
        }
        if(carry) temp->next = new ListNode(carry);
        return head->next;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1->next == nullptr && l2->next == nullptr)
        {
            if(l1->val == 0) return l2;
            else if(l2->val == 0) return l1;
        }
        l1 = reverseLL(l1); 
        l2 = reverseLL(l2);
        ListNode* head = AddLL(l1,l2);
        head = reverseLL(head);
        return head;

    }
};