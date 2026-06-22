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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){return NULL;}//no element case 
        if(head->next==NULL && n==1){return NULL;}//1 element and n=1
        //keep a front pointer and a back pointer, front will always be n steps ahead of back 
        //this results in the back pointer being exactly nth element from behind when the front pointer reaches the end
        //we just need to delete the back->next
        ListNode* front=head;
        ListNode* back=NULL;
        for(int i=0;i<n;i++){
            front=front->next;
        }
        back=head;
        if(front==NULL){return head->next;}//handling the situation that we want to delete the first element
        while(front->next!=NULL)
        {
            front=front->next;
            back=back->next;
        }
        back->next=back->next->next;
        if(head==NULL){return back;}
        return head;
    }
};
