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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) {
            return head;
        }

        ListNode* temp = head;
        int len = 1;
        while (temp->next != NULL) {
            temp = temp->next;
            len++;
        }

        ListNode* last = temp;
        last->next = head;
        k = k % len;
        int l = len - k;
        temp = head;
        for (int i = 1; i < l; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};