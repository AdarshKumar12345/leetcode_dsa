class Solution {
    public int majorityElement(int[] nums) {

        Arrays.sort(nums);
        int cnt = 1;

        int ans = 1;
        int res = nums[0];

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] == nums[i - 1]) {
                cnt++;

            } else
                cnt = 1;

            if (ans < cnt) {
                ans = cnt;
                
                res = nums[i];

            }

        }
        return res;

    }
}