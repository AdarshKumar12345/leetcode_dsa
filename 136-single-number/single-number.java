class Solution {
    public int singleNumber(int[] nums) {
        int[] vis = new int[nums.length];
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 1) {
                continue;
            }
            boolean found = false;

            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j]) {
                    vis[j] = 1;
                    found = true;
                }
            }
            if (found == false)
                return nums[i];

        }
        return -1;

    }
}