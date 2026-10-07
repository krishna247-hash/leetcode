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
 #define Node ListNode
 #define data val
class Solution {
public:
    Node* insert(Node* head,Node* curr)
    {
        Node* temp = head;
        if(temp->data > curr->data)
        {
            curr->next = head;
            return curr;
        }
        while(temp->next != NULL && temp->next->data < curr->data)
        {
            temp = temp->next;
        }

        Node* node = temp->next;
        temp->next = curr;
        curr->next = node;

        return head;
    }
    ListNode* insertionSortList(ListNode* head) {
        
        Node* temp = head;
        if(temp->next == NULL) return head;
       
        while(temp != NULL && temp->next != NULL)
        {
             bool flag = 1;
            if(temp->data > temp->next->data)
            {
                Node* node = temp->next;
                temp->next = temp->next->next;
                head = insert(head,node);
                flag = 0;
            }

            if(flag)
            temp = temp->next;
        }

        return head;
    }
};