class Solution {
    public void dfs(char[][] grid , int[][] vis , int i , int j ){
        if(i < 0 || j< 0 || i >= grid.length || j>= grid[0].length){
            return;
        }
        if(grid[i][j] != '1'){
            return;
        }
        if(vis[i][j]==1){
            return;
            
        }
        vis[i][j] = 1;
        dfs(grid  , vis , i+1 , j);
        dfs(grid  , vis , i , j+1 );
        dfs(grid  , vis , i , j-1);
        dfs(grid  , vis , i-1 , j);
        return;
    }
    public int numIslands(char[][] grid) {

        int n = grid.length;
        int m = grid[0].length;
        int[][] vis = new int[n][m];
        int cnt = 0 ;

        for(int i = 0 ;i< n ;i++){
            for(int j = 0 ;j< m ;j++){
                if(grid[i][j] == '1'&& vis[i][j] == 0){
                    dfs(grid , vis , i , j );
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
}