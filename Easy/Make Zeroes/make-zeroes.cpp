//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> arr = matrix;
        for(int i = 0; i < n; i++){
            for(int j =0 ; j < m; j++){
                if(matrix[i][j] == 0){
                    if(i-1 >= 0){
                        arr[i][j] += matrix[i-1][j];
                        arr[i-1][j] = 0;
                    }
                    if(i + 1 < n){
                        arr[i][j] += matrix[i + 1][j];
                        arr[i+1][j] = 0;
                    }
                    if(j - 1>= 0){
                        arr[i][j] += matrix[i][j-1];
                        arr[i][j-1] = 0;
                    }
                    if(j + 1 < m){
                        arr[i][j] += matrix[i][j+1];
                        arr[i][j + 1] = 0;
                    }
                }
            }
        }
        for(int i =0; i < n; i++){
            for(int j =0; j < m; j++){
                matrix[i][j] = arr[i][j];
            }
        }
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends