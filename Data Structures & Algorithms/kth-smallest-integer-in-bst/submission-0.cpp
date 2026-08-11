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
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count=0;
        recr(root, k , count, ans);
        return ans;
    }
    //recursive helper function
    void recr(TreeNode* root, int k, int& count, int& ans){
        //inorder traversal with a count value check
        if(root==nullptr){
            return ;
        }
        recr(root->left, k , count, ans);
        count++;
        if(count==k){
            ans=root->val;
        }
        recr(root->right, k, count, ans);
    }
};
