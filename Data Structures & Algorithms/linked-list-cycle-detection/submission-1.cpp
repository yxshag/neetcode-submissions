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
    bool hasCycle(ListNode* head) {
        ListNode* curr=head;
        unordered_set<ListNode*> s;
        if(curr==NULL){return false;}
        while(curr->next!=NULL)
        {
            if(s.count(curr)){return true;}
            s.insert(curr);
            curr=curr->next;
        }
        return false;
    }
};
