class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int st=0,maxLen = 1;

        for(int i=0;i<n;i++){
            // odd length palindrome
            solve(s,i,i,st,maxLen);
            // even lenth 
            solve(s,i,i+1,st,maxLen);
        }
        return s.substr(st,maxLen);
    }
    void solve(string &s,int l,int r,int &st,int &maxLen){
        while(l>=0&&r<s.size() && s[l]==s[r]){
            int len = r-l+1;

            if(len>maxLen){
                st=l;
                maxLen=len;
            }

            l--;
            r++;
        }
    }
};