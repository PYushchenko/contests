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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
                ListNode* head = new ListNode(0);
        ListNode* p =  head;
        while (a and b) {
            if (a->val < b->val) {
                p->next = a;
                p = p->next;
                a = a->next;
            } else {
                p->next = b;
                p = p->next;
                b = b->next;
            }
        }
        if (a) {
            p->next = a;
        }
        if (b) {
            p->next = b;
        }
        return head->next;
    }
};

