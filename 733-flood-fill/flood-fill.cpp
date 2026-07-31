class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color)
            return image;


        queue<pair<int , int >> q ;
        int m = image.size();
        int n = image[0].size();
        q.push({sr , sc});


        int val = image[sr][sc];
        image[sr][sc] = color;
        int colx[4] = {0 , 0 , -1 , 1 };
        int rowx[4] = { 1, -1 , 0 , 0};
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0 ;k< 4 ;k++){
                int row = i + colx[k];
                int col = j + rowx[k];
                if(row  >= 0 && row <m && col >= 0 && col < n  ){
                    if(image[row][col] == val){
                        image[row][col] = color;
                        q.push({row , col });

                    }

                }
            }


            
        }
        return image;


        
        
    }
};