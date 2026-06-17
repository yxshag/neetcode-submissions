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
    int height(TreeNode* node) {
        if(node == NULL) return 0;

        int left_height  = height(node->left);
        int right_height = height(node->right);
        if(!(left_height-right_height<=1 && left_height-right_height>=-1)){ans=false;}
        return 1 + max(left_height, right_height);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return ans;
    }
};
