class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int l = 0, maxLen = 0;

        for(int i=0;i<s.size();i++){
            char ch = s[i];

            if (mpp.count(ch)) {
                l = max(l, mpp[ch] + 1);
            }

            mpp[ch] = i;
            maxLen = max(maxLen, i - l + 1);
        }

        return maxLen;
    }
};