class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        return gcd(nums[0],nums[n-1]);
    }
};