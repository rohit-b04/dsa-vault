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
    int getLength(ListNode* head) {
        int len = 0;
        while(head != nullptr) {
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = getLength(headA);
        int lengthB = getLength(headB);
        int diff = max(lengthA, lengthB) - min(lengthA, lengthB);
        while(diff--) {
            if(lengthA > lengthB) headA = headA -> next;
            else headB = headB -> next;
        }
        while(headA != nullptr) {
            if(headA == headB) return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return nullptr;
    }
};
