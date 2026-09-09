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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        vector<int> arr;
        set<int> st;
        for(auto it: nums) 
        st.insert(it);

        ListNode* temp = head;
        while(temp != nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        int i = 0;
        while(i < arr.size() && st.find(arr[i]) != st.end())i++;
        if( i == arr.size()) return nullptr;

        ListNode* newhead = new ListNode(arr[i]);
        

        temp = newhead;
        for(int j = i+1; j < arr.size(); j++)
        {
            if(!(st.find(arr[j]) != st.end()))
            {
                ListNode* newnode = new ListNode(arr[j]);
                temp->next = newnode;
                temp = temp->next;
            }
        }
        return newhead;

    }
};