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

    int maxDiameter = 0;

    int calculateDepth(TreeNode* node){
        if(node == nullptr) return 0;

        int leftDepth = calculateDepth(node->left);
        int rightDepth = calculateDepth(node->right);

        maxDiameter = max(maxDiameter , leftDepth + rightDepth);

        return 1 + max(leftDepth,rightDepth);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        calculateDepth(root);
        return maxDiameter;
    }
};
