/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return nullptr;

        unordered_map<ListNode* , int> mp;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(mp[temp] != 0) return temp;
            else mp[temp]++;
            temp = temp->next;
        }
        return nullptr;
    }
};