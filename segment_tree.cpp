#include <bits/stdc++.h>
using namespace std;

struct segmenttree
{
    int n;
    vector<int> st;

    void init(int _n)
    {
        this->n = _n;
        st.resize(4*n,0);
    }

    void build(int left,int right,int node,vector<int> &v)
    {

        if(right == left){this->st[node] = v[left];return;}
        
        int mid = (left+right)/2;

        build(left,mid,node*2+1,v);
        build(mid+1,right,node*2+2,v);
        this->st[node] = this->st[node*2+1]+this->st[node*2+2];
    }

    int query(int left,int right,int l,int r,int node)
    {
        if(left>r || right<l)return 0;
        if(left>=l && right<=r)return st[node];
        int mid = (left + right)/2;
        
        int q1 = query(left,mid,l,r,node*2+1);
        int q2 = query(mid+1,right,l,r,node*2+2);

        return q1 + q2;
    }

    void update(int left,int right,int node,int index,int val)
    {
        if(left == right)
        {
            st[node] = val;
            return;
        }
        int mid = (left+right)/2;
        if(index<=mid)
        {
            update(left,mid,node*2+1,index,val);
        }
        else
        {
            update(mid+1,right,node*2+2,index,val);
        }
        st[node] = st[node*2+1] +st[node*2+2]; 
    }

    void build(vector<int> &v) {
		build(0, n - 1, 0, v);
	}

    int query(int l, int r) {
		return query(0, n - 1, l, r, 0);
	}

    void update(int ind,int val){
        return update(0,n-1,0,ind,val) ;       
    }


};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
	// cout << v.size();

	segmenttree tree;
	tree.init(v.size());

	tree.build(v);
    // vector<int> t = tree.st;

	cout << tree.query(0, 4) << '\n';
    tree.update(4, 10);
	

	// cout << tree.query(2, 6) << '\n';
	cout << tree.query(0, 4) << '\n';

	return 0;

}
