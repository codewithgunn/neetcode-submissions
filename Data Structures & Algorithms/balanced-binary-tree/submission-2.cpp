class Solution {
private:
    int checkHeight(TreeNode* node) {
        if (!node) return 0;
        
        int leftHeight = checkHeight(node->left);
        if (leftHeight == -1) return -1; // Left subtree is unbalanced

        int rightHeight = checkHeight(node->right);
        if (rightHeight == -1) return -1; // Right subtree is unbalanced

        // Check balance condition for current node
        if (abs(leftHeight - rightHeight) > 1) return -1;

        // Return height of current node
        return 1 + max(leftHeight, rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
};