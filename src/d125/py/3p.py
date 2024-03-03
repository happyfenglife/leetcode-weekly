from typing import List


class Solution:
    def countPairsOfConnectableServers(self, edges: List[List[int]], signalSpeed: int) -> List[int]:
        n = len(edges) + 1
        g = [[] for _ in range(n)]
        for x, y, w in edges:
            g[x].append((y, w))
            g[y].append((x, w))

        def dfs(x: int, fa: int, s: int) -> int:
            cnt = 0 if s % signalSpeed else 1

            for y, w in g[x]:
                if y != fa:
                    cnt += dfs(y, x, s + w)

            return cnt

        ans = [0] * n
        for i, gi in enumerate(g):
            s = 0

            for y, w in gi:
                cnt = dfs(y, i, w)
                ans[i] += cnt * s
                s += cnt

        return ans
