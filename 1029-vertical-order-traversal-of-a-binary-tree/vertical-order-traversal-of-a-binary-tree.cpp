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

    void dfs(map<int, map<int , multiset<int>>>  &nodes  , TreeNode* root , int row , int col ){
        if(root== nullptr)return ;

        nodes[col][row].insert(root-> val);

        dfs(nodes , root->left , row+ 1 , col-1  );
        dfs(nodes , root-> right, row +1 , col+1 );
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans ;
        map<int, map<int , multiset<int>>> nodes ;
        dfs(nodes , root , 0 , 0 );
        for(auto &col : nodes ){
            vector<int> colvalues;
            for(auto &row : col.second){
               for(auto &i : row.second ){
                colvalues.push_back(i);

               }
            }
            ans.push_back(colvalues);

        }
        return ans ;

        


        
    }
};