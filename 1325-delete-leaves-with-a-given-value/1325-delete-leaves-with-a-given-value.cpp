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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
          TreeNode* temp = root;
        if (root == NULL){
            return root;
        }
        
        if(temp->left != NULL){
            temp->left = removeLeafNodes(temp->left, target);
        }

        if(temp->right != NULL){
            temp->right = removeLeafNodes(temp->right, target);
        }

        if(temp->right == NULL && temp->left == NULL){
            if(temp->val == target){
                temp = NULL;
                return temp;
            }
        }

        return root;
    }
};