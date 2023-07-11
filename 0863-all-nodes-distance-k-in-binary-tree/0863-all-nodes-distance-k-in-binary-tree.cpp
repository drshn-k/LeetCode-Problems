class Solution {
public:
    vector<int> ans;
    void solve(int dis,TreeNode* root){
        if(root==NULL){
            return;
        }
        if(dis==0){
            ans.push_back(root->val);
            return;
        }
        solve(dis-1,root->left);
        solve(dis-1,root->right);
    }
    int dfs(TreeNode* root,int k,TreeNode* target){
        if(root==NULL){
            return 0;
        }
        if(root==target){
            if(k==0){
                ans.push_back(root->val);
            }
            else{
            solve(k-1,root->left);
            solve(k-1,root->right);
            }
            return k;
        }
        else{
            int left=dfs(root->left,k,target); 
            int right=dfs(root->right,k,target); 
            if(left>0){
                if(left==1){
                    ans.push_back(root->val);
                }
                else{
                    solve(left-2,root->right);
                }
                return left-1;
            }
            else if(right>0){
                if(right==1){
                    ans.push_back(root->val);
                }
                else{
                    solve(right-2,root->left);
                }
                return right-1;
            }
            return 0;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root,k,target);
        return ans;
    }
};