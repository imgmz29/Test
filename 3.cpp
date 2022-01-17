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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* curr = root;
        TreeNode* parent = NULL;
        
        while(curr != NULL && curr->val != key){
            parent = curr;
            if(curr->val < key)
                curr = curr->right;
            else
                curr = curr->left;
        }
        
        if(curr == NULL) return root;
        
        // no/1/2 children
        if(curr->left == NULL || curr->right == NULL){
            TreeNode* child;
            if(curr->left != NULL)
                child = curr->left;
            else
                child = curr->right;
            if(parent == NULL)
                return child;
            if(curr == parent->left)
                parent->left = child;
            else
                parent->right = child; 
            
            delete curr;  
            return root;
        }
        
        // 2 children
        TreeNode* child = curr->right;
        TreeNode* parent_of_child = NULL;
        while(child->left != NULL){
            parent_of_child = child;
            child = child->left;
        }

        curr->val = child->val; 
        
        if(parent_of_child == NULL){
            curr->right = child->right;
        }
        else{
            if(child == parent_of_child->left)
                parent_of_child->left = child->right;
            else
                parent_of_child->right = child->right;  
        }
        
        delete child;
        return root;
    }
};
