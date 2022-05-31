#include <bits/stdc++.h>
#define int long long int

using namespace std;
vector<int> nums;
int memo[3001][30001];
int dp(int start,int end)
{
    if(start>end)return 0;
    int &ans = memo[start][end];
    if (ans != -1) return ans;
    if((end-start)==1)
    {
        return max(nums[end],nums[start]);
    }
    if((end-start)==0)
    {
        nums[end];
    }
    int ans1 = nums[start]+ min(dp(start+2,end),dp(start+1,end-1));
    // int ans2 = nums[start]+ dp(start+1,end-1);
    int ans3 = nums[end]+ min(dp(start,end-2),dp(start+1,end-1));
    // int ans4 = nums[end]+ dp(start+1,end-1);
    ans = max(ans1,ans3);
    
    return ans;
}


int32_t main()
{
    int N;
    cin>>N;
    int x;
    for(int i=0;i<N;i++)
    {
        cin>>x;
        nums.push_back(x);
    }
    
    int sum = 0;
    for(int i=0;i<nums.size();i++)
    {
        sum += nums[i];
    }
    memset(memo,-1,sizeof(memo));
    int ans = dp(0,nums.size()-1);
    cout<<(2*ans)-sum;

    return 0;
}
