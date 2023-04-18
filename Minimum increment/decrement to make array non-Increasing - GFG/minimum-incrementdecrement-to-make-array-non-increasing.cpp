//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends


class Solution {
public:
    int minOperations(int* a, int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!pq.empty() && pq.top() < a[i]) {
                // debug(pq.top(), a[i]);
                ans += (a[i] - pq.top());
                pq.pop();
                pq.push(a[i]);
            }
            pq.push(a[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int  a[n+1];
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        Solution ob;
        cout<<ob.minOperations(a,n)<<endl;
    }
    
	return 0;
}
// } Driver Code Ends