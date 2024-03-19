import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static long minimumMoves(int[] nums, int k, int maxChanges) {
        List<Integer> pos = new ArrayList<>();
        int c = 0; // nums 中最长连续的 1 长度
        int cnt = 0; // nums 中连续的 1 长度
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                cnt = 0;
            } else {
                pos.add(i);
                cnt++;
                c = Math.max(c, cnt);
            }
        }

        c = Math.min(Math.min(c, 3), k);
        if (maxChanges >= k - c) {
            return Math.max(c - 1, 0) + (k - c) * 2L;
        }

        int n = pos.size();
        long[] sum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + pos.get(i);
        }

        long ans = Long.MAX_VALUE;
        int size = k - maxChanges;
        for (int right = size; right <= n; right++) {
            // s1+s2 是 j 在 [left, right) 中的所有 pos[j] 到 index=pos[(left+right)/2] 的距离之和
            int left = right - size;
            int i = left + size / 2;
            long index = pos.get(i);
            long s1 = index * (i - left) - (sum[i] - sum[left]);
            long s2 = sum[right] - sum[i] - index * (right - i);
            ans = Math.min(ans, s1 + s2);
        }

        return ans + maxChanges * 2L;
    }
}