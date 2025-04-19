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
  // Tc. O(n) Sc. O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(!head || k == 1) return head;

       ListNode* dummy = new ListNode(-1);
       ListNode* temp = head;

       dummy -> next = head;
       ListNode* prevTail = dummy;
       int i = 0;
       while(true) {
        ListNode* check = temp;
        for(int i = 0;i < k;++i) 
        {
            if(!check) return dummy -> next;
            check = check -> next;
        }
        ListNode* tail = temp;
        ListNode* prev = nullptr;
        i = k;
        while(i--) {
            ListNode* fwd = temp -> next;
            temp -> next = prev;
            prev = temp;
            temp = fwd;
        }
        prevTail -> next = prev;
        tail -> next = temp;
        prevTail = tail;
       } 
       return dummy -> next;
    }
};
