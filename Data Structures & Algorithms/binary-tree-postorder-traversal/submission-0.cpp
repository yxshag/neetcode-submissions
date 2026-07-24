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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        recr(root, ans);
        return ans;
    }
    //recursive postorder traversal logic
    void recr(TreeNode* root, vector<int>& ans){
        if(root==nullptr){return;}
        recr(root->left, ans);
        recr(root->right, ans);
        ans.push_back(root->val);
    }
};