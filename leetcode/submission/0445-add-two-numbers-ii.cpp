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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto p = l1;
        ListNode * prev = NULL;
        while (p) {
            auto tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }
        l1 = prev;
        
        p = l2;
        prev = NULL;
        while (p) {
            auto tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }
        l2 = prev;
        
        ListNode * head = new ListNode(-1);
        p = head;
        
        int t = 0;
        while (l1 and l2) {
            ListNode* tmp = new ListNode((l1->val + l2->val + t) % 10);
            t = (l1->val + l2->val + t) / 10;
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode* tmp = new ListNode((l1->val + t) % 10);
            t = (l1->val + t) / 10;
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
        }
        while (l2) {
            ListNode* tmp = new ListNode((l2->val + t) % 10);
            t = (l2->val + t) / 10;
            p->next = tmp;
            p = p->next;
            l2 = l2->next;
        }
        if (t) {
            ListNode* tmp = new ListNode(t);
            p->next = tmp;
        }
        
        
        p = head->next;
        prev = NULL;
        while (p) {
            auto tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }
        head->next = prev;
        
        return head->next;
    }
};
