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
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr){
            return {};
        }
        int h = height(root);
        vector<vector<int>> ans(h);

        dfs(root , 0 , ans);        

        return ans;
    }

    int height(TreeNode* root){
        if(root == nullptr)
        return 0;

        return max(height(root->left) , height(root->right)) + 1;
    }

    void dfs(TreeNode* root , int level, vector<vector<int>>& ans){
        if(root == nullptr)
        return;

        ans[level].push_back(root->val);

        dfs(root->left , level + 1 , ans);
        dfs(root->right , level + 1 , ans);
    }
};