/*
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */



class Solution {
public:

    ListNode* array2LL(vector<int>& arr)
    {
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        
        for(int i = 1; i < arr.size(); i++)
        {
            ListNode* newnode = new ListNode(arr[i]);
            temp->next = newnode;
            temp = temp->next;
        }
        return head;
        
    }

    ListNode* mergeNodes(ListNode* head) {
     vector<int> arr;   
     ListNode* temp = head;
     while(temp != nullptr)
     {
        arr.push_back(temp->val);
        temp = temp->next;
     }

     int n = arr.size();
     vector<int>ans;
     int sum = 0;
     for(int i = 1; i < n; i++)
     {
        if(arr[i] == 0)
        {
            ans.push_back(sum);
            sum = 0;
        }
        else
        {
            sum += arr[i];
        }
     }
     return array2LL(ans);

    }
};