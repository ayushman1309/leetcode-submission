/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int idx=0;
    TreeNode* build(vector<int>& preorder , long long l , long long h){
        if(idx == preorder.size()) return nullptr;
        int val = preorder[idx];

        if(val <= l || val >= h) return nullptr;
        TreeNode* root = new TreeNode(val);
        idx++;

        root->left = build(preorder,l,val);
        root->right = build(preorder,val,h);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,LLONG_MIN,LLONG_MAX);
    }
};