/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <unordered_map>

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        
        unordered_map <ListNode * , bool> visited;
        
        ListNode * curr1 = headA;
        ListNode * curr2 = headB;
        
        while(curr1 != NULL)
        {
            visited[curr1] = true;
            curr1 = curr1->next;
        }
        
        while(curr2 != NULL)
        {
            if(visited[curr2] == true)
            {
                return curr2;
            }
            else
            {
                visited[curr2] == true;
            }
            curr2 = curr2->next;
        }
        return NULL;
    }
        
};

//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(headA == NULL && headB == NULL)
//             return NULL;
        
//         ListNode * curr1 = headA;
//         ListNode * curr2 = headB;
        
//         while(curr1 != NULL)
//         {
//             curr2 = headB;
//             while(curr2 != NULL)
//             {
//                 if(curr1 == curr2)
//                     return curr1;
//                 curr2 = curr2->next;
//             }
//             curr1= curr1->next;
//         }
//         return NULL;
//     }
// };