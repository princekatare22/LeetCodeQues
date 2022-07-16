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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
                 fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        if(slow == head)
        {
            head = NULL;
            return head;
        }
        prev->next = slow->next;
        slow->next = NULL;
        delete slow;
        return head;
    }
};