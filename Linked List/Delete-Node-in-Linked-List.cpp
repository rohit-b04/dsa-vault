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
   // I can't remove myself from the train but I can look like the next person
    void deleteNode(ListNode* node) {
        node -> val = (node -> next) -> val;
        node -> next = (node -> next) -> next;
    }
};
