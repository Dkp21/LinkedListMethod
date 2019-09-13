/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes 
 * of the first two lists.
 * Example:
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 *
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(!l1)
            return l2;
        
        if(!l2)
            return l1;
        
        ListNode *head = nullptr;
        ListNode *newnode = nullptr;
        
        while(l1 && l2)
        {
            ListNode *node = nullptr;
            
            if(l1->val <= l2->val)
            {
                node = l1;
                l1 = l1->next;
            }
            else
            {
                node = l2;
                l2 = l2->next;
            }
            
            if(!head)
            {
                head = node;
                newnode = head;
            }
            else
            {
                newnode->next = node;
                newnode = newnode->next;
            }
        }
        
        newnode->next = (l2)?l2:((l1)?l1:nullptr);
        
        return head;
    }
};
