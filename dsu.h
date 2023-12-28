//https://leetcode.com/problems/minimize-malware-spread

#include <bits/stdc++.h>
using namespace std;


class DSU
{
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if(parent[x] == x)
        {
            return x;
        }
        else
        {
            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    

    int unionSet(int a,int b)
    {
        int parent_a = find(a);
        int parent_b = find(b);
        if(parent_a == parent_b){return 0;}
        if(rank[parent_a] > rank[parent_b])
        {
            parent[parent_b] = parent_a;
        }
        else if(rank[parent_b] > rank[parent_a])
        {
            parent[parent_a] = parent_b;
        }
        else
        {
            parent[parent_a] = parent_b;
            rank[parent_b] += 1; 
        }
        return 1;

    }
};