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
    ListNode* reverseKGroup(ListNode* head, int k) {
    //if no elements present or k=1
        if (head == NULL || k == 1) return head;
        
        //Check if there are at least k nodes left to reverse
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == NULL) return head; // Fewer than k nodes, leave as-is
            check = check->next;
        }
        
        // Reverse k nodes
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextNode = NULL;
        
        for (int i = 0; i < k; i++) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        //head will now be the last node of our k nodes
        if (nextNode != NULL) {
            head->next = reverseKGroup(nextNode, k);
        }
        //prev is our new head;
        return prev;
    }
};
