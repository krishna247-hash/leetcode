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


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<pair<int,ListNode*>> arr;
        for(auto it: lists)
        {
            ListNode* temp = it;
            while(temp != nullptr)
            {
                arr.push_back({temp->val,temp});
                temp = temp->next;
            }
        }

        sort(arr.begin(),arr.end());
        for(int i = 1; i < arr.size(); i++)
        {
            arr[i-1].second->next = arr[i].second;
        }

        if(arr.size() == 0) return NULL;
        return arr[0].second;
    }
};