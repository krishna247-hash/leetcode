
class Solution {
public:
ListNode* MS(ListNode* l1, ListNode* l2)
    {
        ListNode* newhead = new ListNode(0);
        ListNode* temp = newhead;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        while(temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1->val <= temp2->val)
            {
                temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
            }
        }
        while(temp1 != nullptr)
        {
            temp->next = temp1;
                temp = temp->next;
                temp1 = temp1->next;
        }
        while(temp2 != nullptr)
        {
                temp->next = temp2;
                temp = temp->next;
                temp2 = temp2->next;
        }

        return newhead->next;
    }

    ListNode* merge(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
        return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
         ListNode* left = merge(head);
        ListNode* right = merge(mid);
      return MS(left,right);
    }
    ListNode* sortList(ListNode* head) {
        
        head = merge(head);
        return head;
    }
};