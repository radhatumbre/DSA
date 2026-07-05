#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // adjacency matrix for undirected graph
    // time complexity: O(n)
    int adj[n+1][n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // this statement will be removed in case of directed graph
    }
    for(int i = 0; i < n+1; i++)
    {
        for(int j=0; j<m+1; j++){
            cout<< adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}