class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> stt(nums.begin(), nums.end());
        int sum = nums[0];
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1) sum += nums[i];
            else break;
        }
        while (stt.count(sum)) sum++;
        return sum;
    }
};