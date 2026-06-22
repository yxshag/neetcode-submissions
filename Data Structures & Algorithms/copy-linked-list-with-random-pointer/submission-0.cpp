/**
 * Definition for a Node.
 * class Node {
 * public:
 *     int val;
 *     Node* next;
 *     Node* random;
 *     Node(int _val) {
 *         val = _val;
 *         next = NULL;
 *         random = NULL;
 *     }
 * };
 */

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        // Weave copy nodes with original nodes
        // A -> A' -> B -> B' -> C -> C' -> ...
        Node* curr = head;
        while (curr) {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }

        //Assign random pointers for copy nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        //Unweave the two lists
        curr = head;
        Node* dummy = new Node(0);
        Node* copyCurr = dummy;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;   // restore original list
            copyCurr->next = copy;     //building copy list
            copyCurr = copy;
            curr = curr->next;
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};