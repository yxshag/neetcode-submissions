/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool ans=true;
    void check_same(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){ return; }
        if(p==NULL || q==NULL){ ans=false; return; }
        else{
            if((p->left!=NULL && q->left!=NULL)&&(p->left->val==q->left->val)){check_same(p->left,q->left);}else if(!(p->left==NULL && q->left==NULL)){ans=false;}
            if((p->right!=NULL && q->right!=NULL)&&(p->right->val==q->right->val)){check_same(p->right,q->right);}else if(!(p->right==NULL && q->right==NULL)){ans=false;}
        }
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL&&q==NULL){return true;}
        else if(p==NULL || q==NULL){return false;}
        else if(p->val==q->val){
        check_same(p, q);
        return ans;}
        else{return false;}
    }
};
