// Input: V = 5, adj = [[2,3], [1,4,5], [1], [2,5], [4,5]]

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to perform DFS traversal
    void bfs(int v, vector<int> adj[], vector<int>& result) {
        vector<int> visited (v,0);
        visited[0] = 1;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int node = q.front(); 

            // Traverse all neighbours
            for(auto a : adj[node]){
                if(!visited[a]){
                    q.push(a);
                    visited[a] = 1;
                }
            }
            result.push_back(node);
            q.pop();
        }
        return ;

    }
};




int main() {
    // Number of vertices
    int V = 5;

    // Adjacency list
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Result vector
    vector<int> result;

    // Create object
    Solution sol;

    // Run BFS from node 0
    sol.bfs(5, adj, result);

    // Print traversal
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}