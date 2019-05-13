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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (n == m ) return head;
        int tmp = 0;
        ListNode* p = head;
        ListNode* prev = NULL;
        ListNode* begin = NULL;
        ListNode* end = NULL;
        while (p and tmp < n) {
            tmp++;
            if (tmp >= m) {
                if (tmp == m) {
                    begin = prev;
                    end = p;
                }
                ListNode* t = p->next;
                p->next = prev;
                prev = p;
                p = t;
            } else {
                prev = p;
                p = p->next;
            }
        }
        if (begin) {
            begin->next = prev;
        } else  {
           head = prev; 
        }
        end->next = p;
        return head;
    }
};
