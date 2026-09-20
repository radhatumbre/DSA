class Solution {
public:

    void dfs(int ind, vector<vector<int>>& isConnected, vector<int> &vis){
        vis[ind]=1;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[ind][i] && !vis[i]){
                dfs(i,isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> vis(v,0);
        int result =0;
        
        for(int i=0;i<isConnected.size(); i++){
            if(!vis[i]){
                result++;
                dfs(i,isConnected,vis);
            }
        }
        return result;
    }
};