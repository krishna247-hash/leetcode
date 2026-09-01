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

    ListNode* arr2LL(vector<int>& arr)
    {
        if(arr.empty()) return nullptr;
        sort(arr.begin(),arr.end());
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for(int i = 1; i < arr.size(); i++)
        {
            ListNode* newnode = new ListNode(arr[i]);
            temp->next = newnode;
            temp = newnode;
        }

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return nullptr;
        if(n == 1) return lists[0];
        vector<int> arr;
        for(int i = 0; i < n; i++)
        {
            ListNode* temp = lists[i];
            while(temp != nullptr)
            {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }




      return arr2LL(arr);
    }
};