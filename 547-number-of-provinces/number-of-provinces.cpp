class Solution {
private:
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[i] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (i == j)
                continue;

            if (isConnected[i][j] == 1 && vis[j] == -1) {

                dfs(j, isConnected, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int cnt = 0;

        vector<int> vis(n, -1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                dfs(i, isConnected, vis);
                cnt++;
            }
        }
        return cnt;
    }
};