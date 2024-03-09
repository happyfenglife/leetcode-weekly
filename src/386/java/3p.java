import java.util.Arrays;

public class Solution {
    public static int earliestSecondToMarkIndices(int[] nums, int[] changeIndices) {
        int n = nums.length;
        int m = changeIndices.length;
        if (n > m) {
            return -1;
        }

        int[] lastT = new int[n];
        int left = n - 1, right = m - 1;
        int ans = -2;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (check(nums, changeIndices, lastT, mid + 1)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans + 1;
    }

    private static boolean check(int[] nums, int[] changeIndices, int[] lastT, int mx) {
        Arrays.fill(lastT, -1);
        for (int i = 0; i < mx; i++) {
            lastT[changeIndices[i] - 1] = i;
        }

        for (int i : lastT) {
            if (i < 0) { // 有课程没有考试时间
                return false;
            }
        }

        int cnt = 0;
        for (int i = 0; i < mx; i++) {
            int idx = changeIndices[i] - 1;
            if (i == lastT[idx]) {
                if (nums[idx] > cnt) {
                    return false;
                }

                cnt -= nums[idx];
            } else {
                ++cnt;
            }
        }

        return true;
    }
}