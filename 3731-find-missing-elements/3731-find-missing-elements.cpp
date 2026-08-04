class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        if(nums.empty()) return {};
        int minVal = nums[0];
        int maxVal = nums[0];
        for(int num : nums){
            if(num<minVal){
                minVal = num;
            }
            if(num > maxVal){
                maxVal = num;
            }
        }
        unordered_set<int>st(begin(nums) , end(nums));
        vector<int> res;
        for(int i=minVal;i<=maxVal;i++){
            if(st.find(i) == st.end()){
                res.push_back(i);
            }
        }
        return res;

    }
};