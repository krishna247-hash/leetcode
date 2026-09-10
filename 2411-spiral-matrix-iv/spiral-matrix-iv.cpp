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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int left = 0; 
        int right = n - 1;
        int top = 0;
        int bottom = m - 1;
        ListNode* temp = head;

        while(left<= right && top <= bottom)
        {
            for(int i = left; i <= right; i++)
            {
                if(temp != nullptr)
                {
                    ans[top][i] = temp->val;
                    temp = temp->next;
                }
                else
                return ans;
            }
            top++;
            for(int i = top; i <= bottom; i++)
            {
                if(temp != nullptr)
                {
                    ans[i][right] = temp->val;
                    temp = temp->next;
                }
                 else
                return ans;
            }
            right--;
            if(right >= left)
            {
                for(int i = right; i >= left; i--)
                {
                    if(temp != nullptr)
                {
                    ans[bottom][i] = temp->val;
                    temp = temp->next;
                }
                 else
                return ans;
                }
                bottom--;
            }
            if(bottom >= top)
            {
                for(int i = bottom; i >= top; i--)
                {
                   if(temp != nullptr)
                {
                    ans[i][left] = temp->val;
                    temp = temp->next;
                }
                 else
                return ans;  
                }
                left++;
            }
        }
        return ans;
    }
};