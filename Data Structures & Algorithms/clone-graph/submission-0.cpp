/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr){return node;}//handle teh case that no nodes are present in graph
        unordered_map<Node*,Node*> set_of_nodes;
        returnNodeMap(node, set_of_nodes);
        //for every old node-new node pair
        for(auto pair:set_of_nodes){
            //go through each of the old neighbors
            for(auto neighbor:pair.first->neighbors){
                //for each old neighbor, append the corresponding new neighbor address to the new nodes
                pair.second->neighbors.push_back(set_of_nodes[neighbor]);
            }
        }
        return set_of_nodes[node];
    }
    //returns a hashmap of all nodes in the graph mapped to the addresses of all the new nodes with values.
    void returnNodeMap(Node* node, unordered_map<Node*,Node*>& set_of_nodes){
        set_of_nodes[node]=new Node(node->val);
        for(auto i:node->neighbors){
            if(!set_of_nodes[i]){
                cout<<i->val;
                returnNodeMap(i,set_of_nodes);
            }
        }

    }
};
