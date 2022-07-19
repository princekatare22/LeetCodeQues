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
#include <cmath>

class Solution {
public:
    ListNode * reverseList(ListNode * head)
    {
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * forward = NULL;
        while(curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        
        if(head == NULL)
            return ans;
        
        head = reverseList(head);
        ListNode * temp = head;
        int i = 0;
        
        while(temp != NULL)
        {
            ans = ans + temp->val*pow(2,i);
            i++;
            temp = temp->next;
        }
        head = reverseList(head);
        return ans;
    }
};