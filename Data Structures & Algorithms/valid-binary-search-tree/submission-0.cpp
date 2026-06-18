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
    bool ans = true;
    void checkbst(TreeNode* root, long min, long max) {
        if(root == NULL) return;
        if(root->val <= min || root->val >= max) {
            ans = false;
            return;
        }
        checkbst(root->left,  min,       root->val);
        checkbst(root->right, root->val, max);
    }

    bool isValidBST(TreeNode* root) {
        checkbst(root, -1001, 1001);
        return ans;
    }
};
