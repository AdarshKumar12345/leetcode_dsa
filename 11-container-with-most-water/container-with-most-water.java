class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int i = 0 ;
        int j =  n -1 ;
        int max_area = Integer.MIN_VALUE;
        int min_height = Integer.MAX_VALUE;


        while(i <   j ){
            min_height = Math.min(height[i] , height[j]);
            max_area = Math.max(min_height * (j -i ) ,max_area );


            if(height[i] < height[j]){
                i++;
            }
            else j--;



        }
        return max_area;

        
    }
}