//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int i, int j, int n, int m, vector<vector<char>> &mat){
        if(i < 0 or j < 0 or i >= n or j >= m or mat[i][j] != 'O') return;
        mat[i][j] = '#';
        solve(i-1,j,n,m,mat);
        solve(i+1,j,n,m,mat);
        solve(i,j-1,n,m,mat);
        solve(i,j+1,n,m,mat);
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        for(int i = 0; i < m; i++){
            if(mat[0][i] == 'O'){
                solve(0,i,n,m,mat);
            }
            if(mat[n-1][i] == 'O'){
                solve(n-1,i,n,m,mat);
            }
        }
        for(int i = 0; i < n; i++){
            if(mat[i][0] == 'O'){
                solve(i,0,n,m,mat);
            }
            if(mat[i][m-1] == 'O'){
                solve(i,m-1,n,m,mat);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
                if(mat[i][j] == '#'){
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends