#include <bits/stdc++.h>

using namespace std;

// 题目链接: https://leetcode.cn/problems/count-pairs-of-connectable-servers-in-a-weighted-tree-network/description/
class Solution {
 public:
  static vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges, int signalSpeed) {
	int n = edges.size() + 1;
	vector<vector<pair<int, int>>> g(n);
	for (auto &e : edges) {
	  int x = e[0], y = e[1], w = e[2];
	  g[x].emplace_back(y, w);
	  g[y].emplace_back(x, w);
	}

	function<int(int, int, int)> dfs = [&](int x, int fa, int sum) -> int {
	  int cnt = sum % signalSpeed == 0;

	  for (auto &[y, w] : g[x]) {
		if (y != fa) {
		  cnt += dfs(y, x, sum + w);
		}
	  }

	  return cnt;
	};

	vector<int> ans(n);
	for (int i = 0; i < n; ++i) {
	  int sum = 0;

	  for (auto &[y, w] : g[i]) {
		int cnt = dfs(y, i, w);
		ans[i] += cnt * sum;
		sum += cnt;
	  }
	}

	return ans;
  }
};
