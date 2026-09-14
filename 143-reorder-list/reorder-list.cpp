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
    vector<ListNode*> LL2Arr(ListNode* head)
    {
        vector< ListNode* > arr;
        ListNode* temp = head;
        while(temp != nullptr)
        { 
            arr.push_back(temp);
            temp = temp->next;
        }      
        return arr;
    }

    void reorderList(ListNode* head) {
        if(head->next == nullptr || head->next->next == nullptr) return;
        vector<ListNode*> arr = LL2Arr(head);
        int i = 0; int j = arr.size()-1;
        ListNode * newHead = new ListNode(0);
        ListNode* temp = newHead;
        while(i < j)
        {
            temp->next = arr[i];
            temp = temp->next;
            temp->next = arr[j];
            temp = temp->next;
            i++;
            j--;
        }
        if(arr[i] == arr[j]) {
            temp->next = arr[i];
            temp = temp->next;
        }
        temp->next = nullptr;
        head = newHead->next;
    }
};