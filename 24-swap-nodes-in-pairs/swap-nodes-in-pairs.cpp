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
    ListNode* swapPairs(ListNode* head) {
      ListNode* temp = head;

      if(temp == nullptr || temp->next == nullptr) return head;

      ListNode* odd = head;
      ListNode* even = head->next;

      ListNode* newhead = new ListNode(0);
      ListNode* curr = newhead;

      while(even != nullptr)

        {
            ListNode* nextOdd = even->next;
            curr->next = even;
            curr = curr->next;
            curr->next = odd;
            curr = curr->next;
            if(nextOdd == nullptr)
                break;

            odd = nextOdd;
            even = nextOdd->next;
        }

      if(even == nullptr) 
      {
        curr->next = odd;
        curr = curr->next;
      }

      curr->next = nullptr;
      return newhead->next;     
    }
};