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
    
    ListNode* mergeList(ListNode * a, ListNode * b) {
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
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL or head->next == NULL) return head;
        ListNode * ff = head->next;
        ListNode * f = head;
        while (ff and ff->next) {
            f = f->next;
            ff = ff->next->next;
        }
        ListNode * head2 = f->next;
        f->next = NULL;
        return this->mergeList(sortList(head), sortList(head2));
    }
};
