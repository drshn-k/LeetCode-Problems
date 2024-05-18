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
      int ans = 0;

    int solve(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL)
        {
            return root->val - 1;
        }

        int leftVal = 0;
        int rightVal = 0;

        if(root->left != NULL) leftVal = solve(root->left);
        
        if(root->right != NULL) rightVal = solve(root->right);

        int sum = leftVal + rightVal;

        ans += (abs(leftVal) + abs(rightVal));

        return (root->val-1) + sum;

    }
    int distributeCoins(TreeNode* root) {
           solve(root);
            return ans;
    }
};