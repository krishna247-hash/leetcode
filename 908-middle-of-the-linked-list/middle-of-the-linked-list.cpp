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

int countLL(ListNode *head)
{
    ListNode *temp = head;
    int cnt = 0;

    while (temp != nullptr)
    {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}




    ListNode* middleNode(ListNode* head) {
        
        int cnt = countLL(head);

        int k = cnt / 2 + 1;

        cnt = 1;

        ListNode* temp = head;

        while(cnt < k)
        {
            temp = temp->next;
            cnt++;
        }

        return temp;

    }
};