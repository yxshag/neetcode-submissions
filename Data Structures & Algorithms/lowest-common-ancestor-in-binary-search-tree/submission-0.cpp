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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(p==root){return p;}
        else if(q==root){return q;}
        else if((p->val<root->val && q->val>root->val)||(p->val>root->val && q->val<root->val)){return root;}
        else if((p->val<root->val && q->val<root->val)){return lca(root->left,p,q);}
        else if((p->val>root->val && q->val>root->val)){return lca(root->right, p,q);}
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p,q);
    }
};
