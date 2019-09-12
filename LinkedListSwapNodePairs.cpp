/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * Example:
 * Input  - 1->2->3->4,
 * Output - 2->1->4->3.
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode *prev = nullptr;
        
        ListNode *n1 = head;
        
        while(n1 && n1->next)
        {
            if(!prev)
            {
                ListNode *n3 = n1->next->next;
                
                ListNode *n2 = n1->next;
                
                head = n2;
                
                prev = n1;
                
                n1->next = n3;
                
                n2->next = prev;
                
                n1 = n3;
            }
            else
            {
                ListNode *n3 = n1->next->next;
                
                ListNode *n2 = n1->next;
                                
                prev->next = n2;
                
                n1->next = n3;
                
                n2->next = n1;
                
                n1 = n3;
                
                prev = prev->next->next;
            }
        }
        
        return head;
    }
};
