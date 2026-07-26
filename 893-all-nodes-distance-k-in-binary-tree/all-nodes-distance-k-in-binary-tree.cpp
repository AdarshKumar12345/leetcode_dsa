/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void map_parent(unordered_map<TreeNode*, TreeNode*>& parent_map,
               TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                parent_map[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent_map[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> bfs(TreeNode* root, TreeNode* target, int k,
                    unordered_map<TreeNode*, TreeNode*>& parent_map) {
        queue<TreeNode*> q;
        q.push(target);

        vector<int> ans;

        int cnt = 0;

        unordered_set<TreeNode*> visited;
        visited.insert(target);

        while (!q.empty()) {
            int si = q.size();
            if (cnt == k)
                break;
            cnt = cnt + 1;
            for (int i = 0; i < si; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if (node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                }
                if (parent_map.count(node) &&
                    visited.find(parent_map[node]) == visited.end()) {
                    visited.insert(parent_map[node]);
                    q.push(parent_map[node]);
                }
            }
        }
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_map;

        map_parent(parent_map, root);

        return bfs(root, target, k, parent_map);
    }
};