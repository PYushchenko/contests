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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* h = dummy;
        ListNode* hh = dummy;
        for (int i = 0; i < n + 1; i++) {
            hh = hh->next;
        }
        
        while (hh) {
            hh = hh->next;
            h = h->next;
        }
        h->next = h->next->next;
        return dummy->next;
    }
};
