#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static long long minimumMoves(vector<int> &nums, int k, int maxChanges) {
	vector<int> pos;
	int c = 0; // nums 中最长的 连续1的长度
	int cnt = 0;
	for (int i = 0; i < nums.size(); ++i) {
	  if (nums[i] == 0) {
		cnt = 0;
	  } else {
		++cnt;
		pos.push_back(i);
		c = max(c, cnt);
	  }
	}

	c = min({c, 3, k});
	if (maxChanges >= k - c) {
	  return max(c - 1, 0) + (k - c) * 2;
	}

	int n = pos.size();
	vector<long long> sum(n + 1);
	for (int i = 0; i < n; ++i) {
	  sum[i + 1] = sum[i] + pos[i];
	}

	long long ans = LLONG_MAX;
	// 除了 maxChanges 个数可以用两次操作得到，其余的 1 只能一步步移动到 pos[i]
	int sz = k - maxChanges;
	for (int right = sz; right <= n; ++right) {
	  // s1+s2 是 j 在 [left, right) 中的所有 pos[j] 到 index=pos[(left+right)/2] 的距离之和
	  int left = right - sz;
	  int i = left + sz / 2;
	  long long index = pos[i];
	  long long s1 = index * (i - left) - (sum[i] - sum[left]);
	  long long s2 = sum[right] - sum[i] - index * (right - i);
	  ans = min(ans, s1 + s2);
	}

	return ans + maxChanges * 2;
  }
};
