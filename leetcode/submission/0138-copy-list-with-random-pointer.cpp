/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }
        unordered_map<Node *, Node *> map;
        
        Node * p = head;
        
        while (p) {
            Node * n = new Node(p->val, p->next, NULL);
            p->next = n;
            p = p->next->next;
        }
        
        p = head;
        
        while (p) {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        
        Node * res = head->next;
        
        p = head;
        
        while (p) {
            Node * tmp = p->next;
            if (p->next) {
                p->next = p->next->next;
            }
            p = tmp;
        }
        return res;
    }
};
