#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin>>N;
    vector<vector<int>> gr;
    gr.resize(N+1,vector<int>(3));
    for(int i=1;i<N+1;i++)
    {
        int x;
        for(int j=0;j<3;j++)
        {
            cin>>x;
            gr[i][j]= x;
        }
    }
    
    vector<vector<int>> dp(N+1,vector<int>(3,0));
    for(int k=1;k<N+1;k++)
    {
        dp[k][0] = max(dp[k-1][1],dp[k-1][2]) + gr[k][0];
        dp[k][1] = max(dp[k-1][0],dp[k-1][2]) + gr[k][1];
        dp[k][2] = max(dp[k-1][1],dp[k-1][0]) + gr[k][2];
    }
    cout<<max(max(dp[N][0],dp[N][1]),dp[N][2]);
    // return max(max(dp[N][0],dp[N][1]),dp[N][2]);
    return 0;

}