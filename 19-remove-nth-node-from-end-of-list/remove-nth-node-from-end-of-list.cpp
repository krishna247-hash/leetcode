class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int cnt = 0;

        while(temp != nullptr)
        {
            cnt++;
            temp = temp->next;
        }

        if(cnt == n){
            head = head->next;
            return head;
        }

        int k = cnt - n;
        cnt = 1;
        temp = head;

        while(cnt < k)
        {
            temp = temp->next;
            cnt++;
        }

        ListNode* front = temp->next->next;
        temp->next = front;
        return head;

    }
};