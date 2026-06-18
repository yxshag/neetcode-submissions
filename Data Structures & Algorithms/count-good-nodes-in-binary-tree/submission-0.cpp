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
    int countgoodnodes(TreeNode* root,int curr_max){
        int a=0;int b=0;
        if(root->left!=NULL){a=countgoodnodes(root->left,max(curr_max,root->val));}
        if(root->right!=NULL){b=countgoodnodes(root->right,max(curr_max,root->val));}
        if(root->val>=curr_max){
            return 1+a+b;
        }
        else{return a+b;}
    }
    int goodNodes(TreeNode* root) {
        if(root!=NULL){
        return countgoodnodes(root, root->val);}
        return 0;
    }
};
