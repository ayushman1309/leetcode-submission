class Solution {
public:
    bool isValid(string s) {
        stack<char> res;
        int n = s.length();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                res.push(s[i]);
            }
            else{
                if(res.empty()) return false;
                char c = res.top();
                res.pop();
                if((s[i] == ')' && c != '(')|| 
                    (s[i]==']' && c != '[')|| 
                    (s[i] == '}' && c != '{'))
                    return false;
            }
        }

        return res.empty();
    }
};