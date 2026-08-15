class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if (preorder.empty() || inorder.empty()) return nullptr;

        int val = preorder[0];
        TreeNode* root = new TreeNode(val);

        int idx = 0;
        while (inorder[idx] != val) idx++;

        vector<int> leftInorder(inorder.begin(), inorder.begin() + idx);
        vector<int> rightInorder(inorder.begin()+idx+1, inorder.end());

        vector<int> leftPreorder(preorder.begin() + 1,preorder.begin()+1+idx);
        vector<int> rightPreorder(preorder.begin() + 1 + idx,preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};