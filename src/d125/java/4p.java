public class Solution {
    public static long maximumValueSum(int[] nums, int k, int[][] edges) {
        long f0 = 0, f1 = Long.MIN_VALUE;

        for (int x : nums) {
            long t = Math.max(f1 + x, f0 + (x ^ k));
            f0 = Math.max(f0 + x, f1 + (x ^ k));
            f1 = t;
        }

        return f0;
    }
}