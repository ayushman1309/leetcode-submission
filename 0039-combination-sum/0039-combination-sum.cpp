class Solution {
public:
    void solve(vector<int>& candidates,int ind,set<vector<int>>&st,vector<int> v,int target,int n){
        if(ind == n || target < 0){
            return;
        }
        if(target == 0){
            st.insert(v);
            return;
        }

        solve(candidates,ind+1,st,v,target,n);

        v.push_back(candidates[ind]);
        solve(candidates,ind,st,v,target-candidates[ind],n);
        v.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>st;
        vector<int>v;
        int ind = 0;
        int n = candidates.size();

        solve(candidates,ind,st,v,target,n);

        vector<vector<int>>ans;
        for(auto i:st){
            ans.push_back(i);
        }

        return ans;
    }
};