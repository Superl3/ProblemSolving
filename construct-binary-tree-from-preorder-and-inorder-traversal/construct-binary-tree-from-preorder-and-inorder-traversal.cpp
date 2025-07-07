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
    int preidx = 0;
    TreeNode* build(int left, int right, const vector<int>& preorder, const vector<int> &inorderCmp) {
        
        TreeNode* node = new TreeNode(preorder[preidx]);
        int inorderPos = inorderCmp[preorder[preidx]+3000];
        preidx += 1;
        
        if(left < inorderPos)
            node->left = build(left, inorderPos, preorder, inorderCmp);
        if (inorderPos+1 < right)
            node->right = build(inorderPos+1, right, preorder, inorderCmp);
        
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = nullptr;
        
        vector<int> inorderCmp(6001, 0);
        for(int i = 0 ; i < inorder.size();i++)
            inorderCmp[inorder[i]+3000]=i;
        
        root = build(0, inorder.size(), preorder, inorderCmp);
        return root;
    }
};