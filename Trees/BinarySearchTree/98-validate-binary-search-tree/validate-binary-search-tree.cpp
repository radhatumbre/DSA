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
    bool Valid(TreeNode* root, long lowerbound, long upperbound){
        if(root==NULL)  return true;
        if(root->val <= lowerbound || root->val>=upperbound)   return false;
        return Valid(root->left, lowerbound, root->val) && Valid(root->right, root->val, upperbound);
    }
    bool isValidBST(TreeNode* root) {
        return Valid(root, LONG_MIN,LONG_MAX);
    }
};