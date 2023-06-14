//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<bool> &vis, vector<int> adj[]){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, vis, adj);
            }
        }
    }
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        int m = edge.size();
        if(m < n-1) return -1;
        vector<int> adj[n];
        for(int i =0; i < m; i++){
            adj[edge[i][0]].push_back(edge[i][1]);
            adj[edge[i][1]].push_back(edge[i][0]);
        }
        int count = 0; 
        vector<bool> vis(n, false);
        for(int i= 0; i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, adj);
            }
        }
        return count - 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends