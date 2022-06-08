#include <bits/stdc++.h>
#define int long long int

using namespace std;


vector<int> ss(vector<int> v)
{
    int n = v.size();
    vector<int> result;
    for(int i=0;i<(1<<n);i++)
    {
        int sum = 0;
        for(int j=0;j<n;j++)
        {
            if((i>>j)&1){sum += v[j];}
        }
        result.push_back(sum);
    }
    return result;
}

int32_t main()
{
    int N;
    cin>>N;
    int A,B;
    cin>>A>>B;
    vector<int> v(N);

    for(int i=0;i<N;i++)
    {
        cin>>v[i];
    }

    vector<int> vleft;
    vector<int> vright;

    for(int i=0;i<N;i++)
    {
        if(i<=N/2)
        {
            vleft.push_back(v[i]);
        }
        else
        {
            vright.push_back(v[i]);
        }
    }

    vector<int> vls = ss(vleft);
    vector<int> vrs = ss(vright);
    sort(vrs.begin(), vrs.end());

	int ans = 0;

	for (auto x : vls) {
		ans += upper_bound(vrs.begin(), vrs.end(), B - x) -
		       lower_bound(vrs.begin(), vrs.end(), A - x);
	}
    cout<<ans;
    return 0;
}