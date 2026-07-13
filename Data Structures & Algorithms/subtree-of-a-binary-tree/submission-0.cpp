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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        //traverse tree
        return traverseTree(root,subRoot);
    }
    bool recrMatch(TreeNode* root,TreeNode* subroot){

        //check if the values of the current nodes match and also check if the left and right subtrees match.

        if(root==nullptr&&subroot==nullptr){return true;}
        else if((root==nullptr&&subroot!=nullptr)||(root!=nullptr&&subroot==nullptr)){
            return false;
        }
        else 
        if(root->val==subroot->val){
            return recrMatch(root->left,subroot->left)&&recrMatch(root->right, subroot->right);
        }
        else{
            return false;
        }
    }
    bool traverseTree(TreeNode* root, TreeNode* subRoot){

        //goes through the tree and calls recrMatch for all potential candidates

        if(root->val==subRoot->val){
            if(recrMatch(root, subRoot)==true){
                return true;
            }
            }
        if(root->left!=nullptr && root->right!=nullptr){return traverseTree(root->left, subRoot)||traverseTree(root->right,subRoot);}
        else if(root->left!=nullptr) {return traverseTree(root->left, subRoot);}
        else if(root->right!=nullptr){return traverseTree(root->right, subRoot);}
        return false;
    }
};
