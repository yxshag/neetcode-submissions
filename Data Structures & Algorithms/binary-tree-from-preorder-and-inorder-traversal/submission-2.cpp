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
private:
    TreeNode* build(const vector<int> preorder, int& preIdx, 
                   int inStart, int inEnd, unordered_map<int, int>& inMap) {
        if (inStart > inEnd) return nullptr;

        // The current root value is at preorder[preIdx]
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root value in the inorder traversal
        int inIndex = inMap[rootVal];

        // Recursively build the left and right subtrees
        root->left = build(preorder, preIdx, inStart, inIndex - 1, inMap);
        root->right = build(preorder, preIdx, inIndex + 1, inEnd, inMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); ++i) {
            inMap[inorder[i]] = i;
        }

        int preIdx = 0;
        return build(preorder, preIdx, 0, inorder.size() - 1, inMap);
    }
};