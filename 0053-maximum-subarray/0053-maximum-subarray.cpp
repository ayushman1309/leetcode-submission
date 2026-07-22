class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxsum=INT_MIN;
        for(int n : nums){
            curr += n;
            maxsum= max(curr , maxsum);
            if(curr < 0) curr=0;
        }
        return maxsum; 
    }
};