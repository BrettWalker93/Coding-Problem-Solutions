/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {              
        ListNode *done = node->next;
        *node = *done;
        delete done;

        /* 
        node->val = node->next->val;
        node->next = node->next->next;
        */
    }
};
