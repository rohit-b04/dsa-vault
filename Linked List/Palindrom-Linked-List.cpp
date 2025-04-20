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
    // TC: O(n) SC: O(1)
    bool isPalindrome(ListNode* head) {
        if(!head -> next) return true;

        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast -> next) {
            fast = fast -> next;
            slow = slow->next;
            fast = fast -> next;
        }

        ListNode* curr = slow;
        ListNode* prev = nullptr;
        ListNode* fwd;
        while(curr) {
            fwd = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = fwd;
        }
        slow = head;
        while(prev -> val == slow -> val) {
            slow = slow -> next;
            prev = prev -> next;
            if(!prev) return true;
        }
        return false;
    }
};
