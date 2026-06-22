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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;//handling 0 or 1 elements;

        //finding the middle point
        ListNode *mid=head;
        ListNode *dummy=head;
        while(true)
        {
            if(dummy->next==NULL||dummy->next->next==NULL){break;}
            mid=mid->next;
            dummy=dummy->next->next;
        }
        //breaking the link
        ListNode *secondHalf = mid->next;
        mid->next = NULL;
        //reversing the second half of the linked list
        ListNode *revHead;
        ListNode *prev=NULL;
        ListNode *curr=secondHalf;
        ListNode *nex=NULL;
        while (curr != NULL) {
            nex = curr->next;
            curr->next = prev;
            prev = curr;            
            curr = nex;             
        }
        revHead=prev;
        ListNode *rest_org=head->next;
        ListNode *rest_rev=revHead->next;
        while(revHead!=NULL){
            head->next=revHead;
            revHead->next=rest_org;
            head=rest_org;
            rest_org=rest_org->next;
            revHead=rest_rev;
            rest_rev=rest_rev->next;
        }

    }
};
