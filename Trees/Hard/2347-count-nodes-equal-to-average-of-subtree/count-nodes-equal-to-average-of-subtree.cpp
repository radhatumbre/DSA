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
    pair<int,int> sumTree(TreeNode* root, int &count){
        if(root==NULL) return  {0,0};

        auto l = sumTree(root->left,count);
        auto r = sumTree(root->right,count);

        int sum = l.first+r.first+root->val;
        int nodes = l.second+r.second+1;

        int avg = sum/nodes;
        if(root->val == avg) count++;

        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        sumTree(root,count);
        return count;
    }
};