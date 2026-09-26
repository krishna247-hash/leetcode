
class Solution {
public:

   ListNode* reverseLL(ListNode* head)
   {
    ListNode* temp = head;
    ListNode* prev = nullptr;
    while(temp != nullptr)
    {
        ListNode* newnode = temp->next;
        temp->next = prev;
        prev = temp;
        temp = newnode;
    }
    return prev;
   }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int cnt = 0;
        while(temp != 0)
        {
            cnt++;
            temp = temp->next;
        }

        if(cnt < k || k == 1) return head;
        int totalPos = cnt / k - 1;

        temp = head;
        int t = k;
        while(--t)
        {
            temp = temp->next;
        }
        
        ListNode* nextNode = temp->next;
        temp->next = NULL;
        ListNode* newHead = reverseLL(head);
        ListNode* temp1 = newHead;
        while(temp1->next != NULL) temp1 = temp1->next;
        
        while(totalPos--)
        {
            temp = nextNode;
            t = k;
            while(--t && temp != NULL)
        {
            temp = temp->next;
        }
        head = nextNode;
        nextNode = temp->next;
        temp->next = NULL;
         ListNode* Head = reverseLL(head);
         temp1->next = Head;
         temp1 = Head;
         while(temp1->next != NULL) temp1 = temp1->next;
        }
        if(nextNode != NULL) temp1->next = nextNode;
        return newHead;
    }
};