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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        ListNode* cur = NULL;
        priority_queue<pair<int, vector<ListNode*>::iterator>, vector<pair<int, vector<ListNode*>::iterator>>,  std::greater<pair<int, vector<ListNode*>::iterator>>> heap;
        for (auto i = lists.begin(); i < lists.end(); i++) {
            if (*i != NULL) {
                heap.push({(*i)->val, i});
            }
        }
        while (!heap.empty()) {
            auto top = heap.top();
            heap.pop();
            if (cur == NULL) {
                res = *(top.second);
                cur = res;
            } else {
                cur->next = *(top.second);
                cur = cur->next;
            }
            *(top.second) = (*top.second)->next;
            cur->next = NULL;
            if (*(top.second) != NULL) {
                heap.push({(*top.second)->val, top.second});
            }
        }
        return res;
    }
};
