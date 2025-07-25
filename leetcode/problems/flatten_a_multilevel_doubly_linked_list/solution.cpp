/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return nullptr;
        }
        stack<Node*> s;
        Node* curr = head;
        while (curr) {
            if (curr->child) {
                if (curr->next) {
                    s.push(curr->next);
                }
                curr->next = curr->child;
                curr->next->prev = curr;
                curr->child = nullptr;
            }
            if (!curr->next && !s.empty()) {
                curr->next = s.top();
                s.top()->prev = curr;
                s.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};