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
        if(root==NULL)  return NULL;
        if(root->val==key)  return helper(root);
        
        TreeNode* parent=root;
        while(parent){
            if(parent->val<key){
                if(parent->right && parent->right->val==key){
                    parent->right = helper(parent->right);
                    break;
                }
                else    parent = parent->right;

            }
            else{
                if(parent->left && parent->left->val==key){
                    parent->left = helper(parent->left);
                    break;
                }
                else    parent = parent->left;
            }
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL)   return root->right;
        else if(root->right==NULL)   return root->left;

        TreeNode* smallestRight = rightSmallest(root->right);
        smallestRight->left = root->left;

        return root->right;

    }
    TreeNode* rightSmallest(TreeNode* root){
        if(root->left==NULL)  return root;
        return rightSmallest(root->left);
    }
};