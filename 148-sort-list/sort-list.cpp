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
    vector<int> LL2Array(ListNode* head)
    {
        ListNode* temp = head;
        vector<int> arr;
        while(temp != nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return arr;
    }

    ListNode* arr2LL(vector<int>& arr)
    {
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

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
       vector<int> arr =  LL2Array(head);

       sort(arr.begin(),arr.end());
       return arr2LL(arr);

    }
};