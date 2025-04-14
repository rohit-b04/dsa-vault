class Solution {
public:
    int getSize(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp -> next;
        }
        return count;
    }

    ListNode* middleNode(ListNode* head) {
        int size = getSize(head);
        int mid = size/2;
        if(size % 2 == 0) mid = mid+1;
        ListNode* temp = head;
        ListNode* cur;
        while(mid--) {
            cur = temp;
            temp = temp -> next;
        }
        if(size % 2 == 1) return temp;
        return cur;
    }
};
