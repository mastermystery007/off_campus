//https://leetcode.com/problems/sum-of-floored-pairs/description/

//binary search code does not work 
/*
class Solution 
{
public:
const int MOD = 1e9 + 7;
long long sum = 0;
int sumOfFlooredPairs(vector<int>& nums) {
    long long sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = nums.size() - 1; i >= 0; i--) {
        int index = i;
        
        while (index >= 0) {
            int divisor = nums[i];
            int dividend = nums[index];
            int quotient = divisor / dividend;
            auto ub = upper_bound(nums.begin(), nums.end(), nums[i] / quotient) - nums.begin();
            auto lb = upper_bound(nums.begin(), nums.end(), nums[i] / (quotient + 1)) - nums.begin();
            int count = ub - lb;

            
            sum = (sum + (long long)quotient * count) % MOD;
            index = lb - 1;

            
        }
        //cout << "Total Sum after nums[" << i << "]: " << sum << endl << endl;
    }
    return sum;
}
};

*/