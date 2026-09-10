/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bfsFromTarget(TreeNode* root, int k, vector<int> &result, map<TreeNode* , TreeNode* > mp){
        unordered_set<TreeNode*> visited; 
        queue<TreeNode*> q;
        q.push(root);
        visited.insert(root);
        int distance =0;
        while(!q.empty()){
            int n = q.size();
            if (distance == k) {
                while (!q.empty()) {
                    result.push_back(q.front()->val);
                    q.pop();
                }
                return;
            }
            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();
                if(mp.find(node)!=mp.end() && visited.find(mp[node])==visited.end()){
                    q.push(mp[node]);
                    visited.insert(mp[node]);
                }
                if(node->left && visited.find(node->left)==visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right)==visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
            distance++;
        }
    }
    void getParentMap(TreeNode* root, map<TreeNode* , TreeNode* > &mp){
        if(root==NULL)  return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left)  {
                mp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mp[node->right] = node;
                q.push(node->right);
            }
        }
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        map<TreeNode* , TreeNode* > mp;
        getParentMap(root, mp);
        bfsFromTarget(target,k,result,mp);
        return result;
        
    }
};