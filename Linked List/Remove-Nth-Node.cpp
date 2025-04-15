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
    int getLength(ListNode* head) {
        int count = 0;
        while(head != nullptr) {
            count++;
            head = head -> next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLength(head);
        if(len == 1) return nullptr;
        if(len == n) return head -> next;
        ListNode* temp = head;
        ListNode* toDel = temp;
        int it = len - n;
        while((it--)) {
            toDel = temp;
            temp = temp -> next;
            
        }
        toDel -> next = temp -> next;
        return head;
    }
};
