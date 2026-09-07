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
    void traverse(TreeNode* root, vector<string> &result, string path){
        if(root->left==NULL && root->right==NULL){
            result.push_back(path);
        }
        path += "->";
        if(root->left) {
            string pathl = path + to_string(root->left->val);
            traverse(root->left, result,pathl);
        }
        if(root->right){
            string pathr = path + to_string(root->right->val);
            traverse(root->right, result,pathr);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root==NULL)  return result;
        string path = to_string(root->val);
        traverse(root,result,path);
        return result;
    }
};