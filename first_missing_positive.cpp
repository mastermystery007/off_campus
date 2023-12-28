// #include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) 
{
    int size = nums.size();
    int index = 0;
    while(index < size)
    {
        int e = nums[index];
        if(e > size || e < 1 || nums[e-1] == nums[index]){index++;continue;}
        
        swap(nums[e-1],nums[index]);
        if(nums[index] == index + 1){index++;continue;}
    }
    for(int i=0;i<size;i++)
    {
        cout<<nums[i]<<" ";
        if(nums[i] != i+1)return i+1;
    }
    return size+1;
}




int main()
{
    int n;
    cin>>n;
    
    vector<int> arr;
    arr.resize(n);
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        arr.push_back(c);
    }

    int ans = firstMissingPositive(arr);
}


