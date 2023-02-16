//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void add(stack<int> &s, int x){
        if(s.size() == 0){
            s.push(x);
            return;
        }
        int top_ = s.top();
        s.pop();
        add(s,x);
        s.push(top_);
    }
    void Reverse(stack<int> &s){
        if(s.size() == 0){
            return;
        }
        int top_ = s.top();
        s.pop();
        Reverse(s);
        add(s,top_);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends