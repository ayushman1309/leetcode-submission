class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        int maxx = 0;

        for(int i=0;i<n;i++){
            if(nums[i] > maxx) maxx = nums[i];
            nums[i] = gcd(maxx , nums[i]);
        }
        sort(begin(nums),end(nums));

        int l=0,r=n-1;

        long long res =0;
        while(l<r){
            res += gcd(nums[l],nums[r]);
            l++;
            r--;
        }
        return res;
        
    }
};