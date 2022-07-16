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
    void insertAttail(ListNode* &tail , ListNode* curr)
    {
        tail->next = curr;
        tail = curr;
    }
    
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * currHead = new ListNode(-1);
        ListNode * currTail = currHead;
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        while(list1 !=  NULL || list2 != NULL)
        {
            if(list2 == NULL)
            {
                insertAttail(currTail,list1);
                return currHead->next;
            }
            else if(list1 == NULL)
            {
                insertAttail(currTail,list2);
                return currHead->next;
            }
            else if(list1->val <= list2->val)
            {
                insertAttail(currTail,list1);
                list1 = list1->next;
            }
            else if(list1->val >= list2->val)
            {
                insertAttail(currTail,list2);
                list2 = list2->next;
            }
        }
        return currHead->next;
    }
};