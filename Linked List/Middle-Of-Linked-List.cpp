class Solution {
public:
   // Fast and slow approach (Optimized)
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if(head == nullptr || head -> next == nullptr) return head;
        if((head->next)->next == nullptr) return head->next;

        while(fast != nullptr) {
            fast = fast -> next;
            if(fast == nullptr) break;
            fast = fast -> next;
            slow = slow -> next;
            
        }
        return slow;
    }
};
