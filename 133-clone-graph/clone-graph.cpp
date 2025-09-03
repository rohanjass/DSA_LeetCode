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
    Node* clone(Node* node,unordered_map<Node*,Node*>& mp){
        if(node==nullptr) return nullptr;
        if(mp.count(node)) return mp[node];
        Node* copy=new Node(node->val);
        mp[node]=copy;
        for(auto& n:node->neighbors){
            copy->neighbors.push_back(clone(n,mp));
        }
    return copy;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        return clone(node,mp);
    }
};