class Solution {
    public int maxSubArray(int[] nums) {
        if(nums.length==1 )return nums[0];

        int maxsum = Integer.MIN_VALUE ;
        int currentsum = 0 ;
        for(int i = 0 ;i< nums.length;i++){
            currentsum = Math.max(currentsum + nums[i], nums[i]);
            if(maxsum < currentsum ){
                maxsum = currentsum;

            }
        }
        return maxsum;

        
    }
}