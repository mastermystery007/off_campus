#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    vector<vector<int>> dp;
    int maxCoins(vector<int> & nums)
    {
        int n = nums.size();
        dp.resize(n+1,vector<int>(n+1,-1));
        vector<int> all;
        all.push_back(1);
        for(int i=0;i<n;i++){all.push_back(nums[i]);}
        all.push_back(1);
        return helper(all,1,n);
    }

    int helper(vector<int>& all,int start , int end)
    {
        if(start > end) return 0;
        if(dp[start][end] != -1){return dp[start][end];}

        int maxm = -1;
        for(int divide = start;divide <= end;divide++)
        {
            int coins = all[start-1] * all[divide] * all[end+1];
            maxm = max(maxm , helper(all,start,divide-1) + helper(all,divide+1,end) + coins);
        }

        return dp[start][end] = maxm;
    }

};