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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        {
            return head;
        }
        ListNode * prev = NULL;
        ListNode * curr = head;
        ListNode * forward = NULL;
        int count = k;
        while(curr!= NULL && count>0 )
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            count--;
        }
        if(count>0)
        {
            return reverseKGroup(prev,k-count);
        }
        head->next = reverseKGroup(forward, k);
        return prev;
    }
};