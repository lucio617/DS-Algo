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
    bool containsOne(TreeNode* root){
        if(root==nullptr) return false;
        
        bool leftSubTree=containsOne(root->left);
        
        bool rightSubTree=containsOne(root->right);
        
        if(leftSubTree==false) root->left=nullptr;
        if(rightSubTree==false) root->right=nullptr;
        
        if(root->val==1)
            return true;
        return leftSubTree or rightSubTree;
    }
    TreeNode* pruneTree(TreeNode* root) {
         
         bool temp=containsOne(root);
        if(temp==false)
            return nullptr;
         return root;
    }
};