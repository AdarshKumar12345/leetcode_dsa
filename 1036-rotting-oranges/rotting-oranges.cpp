class Solution {
private:
    int isallroten(vector<vector<int>>& ans) {
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[0].size(); j++) {
                if (ans[i][j] == 1) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0 ;


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({0 , {i, j}});
                }
            }
        }
        int colx[4] = {1, -1, 0, 0};
        int rowx[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            int s = q.size();
            

            for (int l = 0; l < s; l++) {
                int i = q.front().second.first;
                int j = q.front().second.second;
                int cnt= q.front().first;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int row = i + colx[k];
                    int col = j + rowx[k];
                    if (row >= 0 && col >= 0 && row < m && col < n) {
                        if (grid[row][col] == 1) {
                            grid[row][col] = 2;

                            q.push({cnt+1 ,{row, col}});
                            ans = cnt +1 ;

                        }
                    }
                }
            }
           

        }
        return isallroten(grid) ? ans  : -1;
    }
};