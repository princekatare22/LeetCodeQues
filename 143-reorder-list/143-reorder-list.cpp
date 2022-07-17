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
    ListNode * findMiddle(ListNode * head)
    {
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
                fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
    
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
    
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        ListNode * middle = findMiddle(head);
        // cout << middle->val;
        ListNode * temp = middle->next;
        middle->next = reverseList(temp);
        
        ListNode * curr1 = head;
        ListNode * next1 = NULL;
        ListNode * curr2 = middle->next;
        ListNode * next2 = NULL;
        
        
        while(curr2 != NULL && curr1 != middle)
        {
            next1 = curr1->next;
            next2 = curr2->next;
            
            curr1->next = curr2;
            curr2->next = next1;
            
            curr1 = next1;
            curr2 = next2;
        }
        middle->next = NULL;
    }
};