/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 */

// @lc code=start
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
private:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;
    
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        
        // 中序遍历左子树
        inorder(root->left);
        
        // 处理当前节点
        if (prev != nullptr) {
            minDiff = min(minDiff, root->val - prev->val);
        }
        prev = root;
        
        // 中序遍历右子树
        inorder(root->right);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return minDiff;
    }
};
// @lc code=end

