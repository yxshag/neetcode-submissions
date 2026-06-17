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
    void change(TreeNode* main){
        if(main->left==NULL && main->right==NULL){return ;}
        if(main->left!=NULL){
        change(main->left);}
        if(main->right!=NULL){
        change(main->right);}
        TreeNode* dummy=main->left;
        main->left=main->right;
        main->right=dummy;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){return root;}
        change(root);
        return root;
    }
};
