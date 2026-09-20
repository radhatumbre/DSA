class Solution {
public:

    void dfs(int ind, int v,vector<vector<int>>& isConnected, vector<int> &vis){
        vis[ind]=1;
        for(int i=0;i<v;i++){
            if(isConnected[ind][i] && !vis[i] && i!=ind){
                dfs(i,v,isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> vis(v,0);
        int result =0;
        for(int i=0;i<v; i++){
            if(!vis[i]){
                result++;
                dfs(i,v,isConnected,vis);
            }
        }
        return result;
    }
};