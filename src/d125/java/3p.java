import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Solution {
    public static int[] countPairsOfConnectableServers(int[][] edges, int signalSpeed) {
        int n = edges.length + 1;
        List<int[]>[] g = new ArrayList[n];
        Arrays.setAll(g, i -> new ArrayList<>());

        for (int[] e : edges) {
            int x = e[0], y = e[1], w = e[2];
            g[x].add(new int[]{y, w});
            g[y].add(new int[]{x, w});
        }

        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int[] e : g[i]) {
                int y = e[0], w = e[1];
                int cnt = dfs(y, i, w, g, signalSpeed);
                ans[i] += cnt * sum;
                sum += cnt;
            }
        }

        return ans;
    }

    private static int dfs(int x, int fa, int sum, List<int[]>[] g, int signalSpeed) {
        int cnt = sum % signalSpeed == 0 ? 1 : 0;

        for (int[] e : g[x]) {
            int y = e[0], w = e[1];

            if (y != fa) {
                cnt += dfs(y, x, sum + w, g, signalSpeed);
            }
        }

        return cnt;
    }
}