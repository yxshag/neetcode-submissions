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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //if either of the lists is null , return the other one
        if(l1==NULL){return l2;}
        if(l2==NULL){return l1;}
        //create starting node
        ListNode* head=new ListNode();
        int carry=0;
        //create curr pointer
        ListNode* curr=head;
        //while loop
        while(l1 != NULL || l2 != NULL || carry != 0){
            int a=0;int b=0;
            //get value of the next numbers in both lists
            if(l1!=NULL){a=l1->val;l1=l1->next;}
            if(l2!=NULL){b=l2->val;l2=l2->next;}
            //update value and carry
            int value=(a+b+carry)%10;
            carry=(a+b+carry)/10;
            curr->val=value;
            //only create new node if work is left to do 
            if (l1 != NULL || l2 != NULL || carry != 0) {
                curr->next = new ListNode();
                curr = curr->next;
        }}
        return head;
        
        
    }
};
