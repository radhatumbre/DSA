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
    void recursive(TreeNode* root,int level, vector<int> &result){
        if(root==NULL)  return;

        if(level==result.size())    result.push_back(root->val);
        if(root->left) recursive(root->left, level+1, result);
        if(root->right) recursive(root->right, level+1, result);
        return;
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> result;
        recursive(root,0,result);
        return result.back();
    }
};