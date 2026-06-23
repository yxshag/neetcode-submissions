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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode();
        ListNode* curr=head;
        int count=0;
        //count number of nodes
        for(auto i:lists)
        {
            ListNode* dummy=i;
            while(dummy!=NULL){
                dummy=dummy->next;
                count++;
            }
        }
        //run loop count times
        while(count!=0){
            int min_index;
            ListNode* min_node=NULL;
            //loop to find which index is the one that is the next in line
            for(int i=0;i<lists.size();i++){
                if(lists[i] != NULL && (min_node == NULL || min_node->val > lists[i]->val)){
                    min_node=lists[i];min_index=i;
                }
            }
            count--;
            //add the element to the linked list, change the pointer in the lists, and break the link 
            curr->next=min_node;
            lists[min_index]=min_node->next;
            curr=curr->next;
            curr->next=NULL;
        }
        return head->next;
    }
};
