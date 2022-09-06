/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        
        q.push(root);
        
        vector<vector<int>> res;
        if(root==nullptr) return res;
        while(!q.empty()){
           
            int size=q.size();
           
            vector<int> temp;
            
            for(int i=0;i<size;i++){
                    Node* node=q.front();
                vector<Node*> v=node->children;
                temp.push_back(node->val);
                     q.pop();
                    
                    for(int j=0;j<v.size();j++){
                        q.push(v[j]);
                    }
            }
            
            res.push_back(temp);
        }
        return res;
    }
};