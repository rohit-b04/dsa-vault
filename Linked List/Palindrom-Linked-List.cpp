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
    bool isPalindrome(ListNode* head) {
        if(!head -> next) return true;
        vector<int> arr;
        ListNode* fast = head;
        ListNode* slow = head;

        while(fast && fast -> next) {
            arr.push_back(slow->val);
            fast = fast -> next;
            slow = slow->next;
            fast = fast -> next;
        }
        if(fast) slow = slow -> next; // It means the list is having odd length
        int i = arr.size()-1;
        while(slow -> val == arr[i--]) {
            slow = slow -> next;
            if(!slow || i < 0) return true;
        }
        return false;
    }
};
