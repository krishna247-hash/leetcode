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

    vector<int> LL2Arr(ListNode* head)
    {
        vector<int> arr;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return arr;
    }

   int GCD(int a, int b)
{
    if(a == b)
        return a;

    else if(a > b)
        return GCD(a - b, b);

    else
        return GCD(a, b - a);
}

    ListNode* array2LL(vector<int>& arr)
    {
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i = 1; i < arr.size(); i++)
        {
            ListNode* newNode = new ListNode(arr[i]);
            temp-> next = newNode;
            temp = newNode;
        }
        return head;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        vector<int> temp = LL2Arr(head); 
        vector<int> ans;

        for(int i = 1; i < temp.size(); i++)
        {
            ans.push_back(temp[i-1]);
            ans.push_back(GCD(temp[i-1],temp[i]));
        }
        ans.push_back(temp[temp.size()-1]);

        return array2LL(ans);


    }
};