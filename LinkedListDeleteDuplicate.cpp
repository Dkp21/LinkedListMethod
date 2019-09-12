/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Remove duplicates from a sorted linked list.
 * Original - 1  2  3  4  4  5  5   6
 * Output   - 1  2  3  4  5  6
 *
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !(head->next))
            return head;
        
        ListNode* n = head;
        
        while(n->next)
        {
            if(n->val == (n->next->val))
            {
                ListNode *ptr = n->next;
                
                n->next = n->next->next;
                
                delete ptr;
            }
            else
            {
                n = n->next;
            }
        }
        
        return head;       
    }
};
