//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
        int mod = 1e9 + 7;
        vector<long long> ans(n, 0);
        vector<long long> time(n, 1e18);
        vector<pair<long long,long long>> adj[n];
        for(int i =0; i < roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        pq.push({0, 0});
        ans[0] = 1;
        time[0] = 0;
        while(!pq.empty()){
            auto tq = pq.top();
            pq.pop();
            long long d = tq.first;
            long long node = tq.second;
            for(auto it : adj[node]){
                long long di = it.second;
                if((1ll*d + 1ll*di) < time[it.first]){
                    pq.push({d+di, it.first});
                    time[it.first] = (1ll*d + 1ll*di);
                    ans[it.first] = ans[node];
                }
                else if((d+di) == time[it.first]){
                    // pq.push({d+di, it.first});
                    ans[it.first] = (ans[it.first]%mod + ans[node]%mod)%mod;
                }
            }
        }
        return ans[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends