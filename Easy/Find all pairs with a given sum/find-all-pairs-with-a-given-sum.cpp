//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector<pair<int,int>> allPairs(int A[], int B[], int N, int M, int X)
    {
        // Your code goes here  
        sort(A, A+N);
        sort(B, B+M);
        vector<pair<int,int>> ans;
        for(int i = 0; i < N; i++){
            int sum = X - A[i];
            int l = 0, r = M-1;
            while(l <= r){
                int mid = (l + r)/2;
                if(B[mid] == sum){
                    ans.push_back({A[i], B[mid]});
                    // cout << A[i] << " " << B[mid]<< endl;
                    break;
                }
                else if(B[mid] > sum){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin >> t;
	
	while(t--){
	    int N, M, X;
	    cin >> N >> M >> X;
        int A[N], B[M];
        
	    for(int i = 0;i<N;i++)
	        cin >> A[i];
	    for(int i = 0;i<M;i++)
	        cin >> B[i];
	        
	   Solution ob;
	   vector<pair<int,int>> vp = ob.allPairs(A, B, N, M, X);
	   int sz = vp.size();
        if(sz==0)
        cout<<-1<<endl;
        else{
            for(int i=0;i<sz;i++){
                if(i==0)
                cout<<vp[i].first<<" "<<vp[i].second;
                else
                cout<<", "<<vp[i].first<<" "<<vp[i].second;
            }
            cout<<endl;
        }
	}
	return 0;
}
// } Driver Code Ends