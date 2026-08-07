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
    ListNode* removeElements(ListNode* head, int val) {
        // Dummy node pointing to head handles edge cases (e.g., removing head itself)
        ListNode* dummy = new ListNode(0, head);
        ListNode* curr = dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                // Node to be removed found; save reference and un-link it
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp; // Free memory to avoid memory leaks
            } else {
                // Move to next node only if no deletion occurred
                curr = curr->next;
            }
        }

        ListNode* newHead = dummy->next;
        delete dummy; // Clean up dummy node memory
        return newHead;
    }
};