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
  // Brute force T.C.O(n) S.C. O(n)
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> v;
        ListNode* temp = head;
        while(temp != NULL) {
            v.push_back(temp -> val);
            temp = temp -> next;
        }
        for(int i = 0;i + k <= v.size();i+=k) reverse(v.begin()+i, v.begin() + i+ k );

        ListNode* newList = new ListNode(v[0]);
        temp = newList;
        for(int i =1;i < v.size();i++) {
            ListNode* node = new ListNode(v[i]);
            temp -> next = node;
            temp = temp -> next;
        }
        return newList;
    }
};
