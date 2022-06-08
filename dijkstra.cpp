#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<int> curr_time;
        curr_time.resize(n+1,INT_MAX);
        set<pair<int,int>> gr;
        gr.insert({0,k}); // the curr_ditance,node pair 
        curr_time[k] = 0;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            int src  = times[i][0];
            int dest = times[i][1];
            int wt   = times[i][2];
            adj[src].push_back({dest,wt});
        }
        while(!gr.empty())
        {
            auto ele = gr.begin();
            int n = ele->second;
            int w = ele->first;
            // cout<<n<<" "<<w<<"\n";
            gr.erase(ele);
            for(auto nbr:adj[n])
            {
                int new_wt = nbr.second+w;
                if(new_wt<curr_time[nbr.first])
                {
                    if(gr.find({curr_time[nbr.first],nbr.first}) != gr.end())
                    {
                        gr.erase({curr_time[nbr.first],nbr.first});
                    }
                    curr_time[nbr.first] = new_wt;
                    gr.insert({new_wt,nbr.first});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<curr_time.size();i++)
        {
            if(i==k)continue;
            ans = max(ans,curr_time[i]);
        }
        if(ans == INT_MAX)return -1;
        return ans;
        
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> v = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    cout<<sol.networkDelayTime(v,n,k);

}