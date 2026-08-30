class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* temp;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        if(temp1 == nullptr && temp2 == nullptr)
            return nullptr;

        if(temp1 == nullptr)
            return temp2;

        if(temp2 == nullptr)
            return temp1;

        if(temp1->val <= temp2->val)
        {
            temp = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp = temp2;
            temp2 = temp2->next;
        }

        ListNode* head = temp;

        while(temp1 != nullptr && temp2 != nullptr)
        {
            if(temp1->val <= temp2->val)
            {
                temp->next = temp1;   
                temp1 = temp1->next;
            }
            else
            {
                temp->next = temp2;   
                temp2 = temp2->next;
            }

            temp = temp->next;        
        }

        if(temp1 != nullptr)
            temp->next = temp1;

        if(temp2 != nullptr)
            temp->next = temp2;

        return head;
    }
};