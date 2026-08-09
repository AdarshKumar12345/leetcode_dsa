class Solution {
    public int singleNumber(int[] nums) {
        Map<Integer, Integer> freq = new HashMap<>();
        int n = nums.length;

        
        for(int i = 0;i< n ;i++){
            freq.put(nums[i] , freq.getOrDefault(nums[i] , 0 )+1  );


        }
        for(int i = 0 ;i< n ;i++){
            if(freq.get(nums[i]) == 1){
                return nums[i];

            }
        }
        return -1;

        
    }
}