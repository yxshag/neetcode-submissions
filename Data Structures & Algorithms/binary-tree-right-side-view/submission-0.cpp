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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return {};
        queue<TreeNode*> q;
        TreeNode* dummy = new TreeNode();

        q.push(root);
        q.push(dummy);
        vector<int> ans;
        vector<int> level;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if (curr==dummy){level.clear();if(!q.empty()){q.push(dummy);}continue;}
            if (q.front()==dummy){ans.push_back(curr->val);}
            level.push_back(curr->val);
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
        }
        return ans;
    }
};
