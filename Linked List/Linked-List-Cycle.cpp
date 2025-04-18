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
  // Floyd's cycle detection algorithm (tortoise and hare approach)
  // T.C: O(n)  S.C: O(1)
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast -> next) {
            fast = fast -> next;
            fast = fast -> next;
            slow = slow -> next;
            if(fast == slow) return true;
        }     
        return false;
    }
};
