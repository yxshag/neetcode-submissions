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

class Codec {
private:
    void helperS(TreeNode* root, string& ans){
        //helper function for serialising the tree.
        //works based on pre order traversal
        if(root==nullptr){
            ans+="#,";
            return ;
        }
        ans+=to_string(root->val);
        ans+=',';
        helperS(root->left, ans);
        helperS(root->right, ans);
    }
    TreeNode* helperD(queue<int>& q){
        //go thru elements in the queue and build the tree in preorder form
        if(q.front()==2000){
            q.pop();
            return nullptr;
        }
        TreeNode* root=new TreeNode(q.front());
        q.pop();
        root->left=helperD(q);
        root->right=helperD(q);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        helperS(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='#'){
            return nullptr;
        }
        queue<int> q;
        int start=0;
        int curr=0;
        //convert string to queue
        while(curr<data.size()){
            if(data[curr]==',')
            {
                if(data.substr(start, curr-start)=="#"){
                    //using 2000 as a placeholder for nullptr
                    q.push(2000);
                }
                else{
                    q.push(stoi(data.substr(start, curr-start)));
                }
                start=curr+1;
            }
            curr++;
        }
        TreeNode* root=new TreeNode(q.front());
        q.pop();
        root->left=helperD(q);
        root->right=helperD(q);
        return root;
    }
};
