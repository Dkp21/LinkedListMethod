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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head)
            return nullptr;
        
        int len = 0;
        
        ListNode *temp = head;
        while(temp)
        {
            ++len;
            temp = temp->next;
        }
        
        if(n == len)
        {
            ListNode *d = head;
            
            return head->next;
        }
        
        ListNode *curr = head;
        ListNode *prev = nullptr;
        
        for(int i = 0; i < (len - n); ++i)
        {
            prev = curr;
            curr = curr->next;
        }
        
        ListNode *d = curr;
        
        prev->next = curr->next;
        
        delete d;
        
        return head;
    }
};
