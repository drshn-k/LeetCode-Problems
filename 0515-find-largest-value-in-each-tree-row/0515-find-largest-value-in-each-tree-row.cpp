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
    vector<int> ans;
    
    void traversal(TreeNode* root , int level){
        if(!root)return ;
            
        if(level < ans.size()){
            if(ans[level] < root->val)ans[level] = root->val;
        }
        else{
            ans.push_back(root->val);
        }
        
        traversal(root->left, level+1);
        traversal(root->right, level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        
        
        traversal(root , 0);
        
        return ans;
        
    }
};