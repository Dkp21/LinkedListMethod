/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers, 
 * leaving only distinct numbers from the original list.
 * Example 1:
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head)
            return head;
        
        ListNode *prev = nullptr;
        
        ListNode *node = head;
        
        int v;
        
        while(node && node->next)
        {
            v = node->val;
            if((node->val == node->next->val))
            {        
                if(!prev)
                {
                    do
                    {
                        head = node->next;
                        delete node;
                        node = head;
                        
                    } while(node && (v == node->val));
                }
                else
                {
                    do
                    {
                        prev->next = node->next;
                        delete node;
                        node = prev->next;
                    } while(node && (v == node->val));
                }
                
            }
            else
            {
                prev = node;
                node = node->next;
            }
        }
        
        return head;
        
    }
};
