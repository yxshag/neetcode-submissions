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
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        recr(root, maxi);
        return maxi;
    }
    int recr(TreeNode* root, int& maxi){
        if(root==nullptr){
            return 0;
        }
        int leftSum=recr(root->left, maxi);
        int rightSum=recr(root->right, maxi);
        maxi=max(maxi, leftSum+rightSum+root->val);
        //we also doing max with 0 in the case that both subtrees is negative sum.
        return max(0,root->val+max(leftSum, rightSum));
    }
};
