/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(vector<vector<int>>& ans, TreeNode* root) {
        if (root == nullptr)
            return;

        queue<TreeNode*> q;
        int rev = 0;

        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> row;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                row.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if(node-> right){
                    q.push(node-> right);
                }
            }
            if (rev == 1) {
                rev = 0;
                reverse(row.begin() , row.end());
                

            } else
                rev= 1;

            ans.push_back(row);
            
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> ans;

        solve(ans, root);

        return ans;
    }
};