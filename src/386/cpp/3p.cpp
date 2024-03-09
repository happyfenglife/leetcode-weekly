#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices) {
	int n = nums.size(), m = changeIndices.size();
	if (n > m) return -1;

	vector<int> last_t(n);
	auto check = [&](int mx) -> bool {
	  ranges::fill(last_t, -1);

	  for (int t = 0; t < mx; ++t) {
		last_t[changeIndices[t] - 1] = t;
	  }

	  if (ranges::find(last_t, -1) != last_t.end()) {
		return false;
	  }

	  int cnt = 0;
	  for (int i = 0; i < mx; ++i) {
		int idx = changeIndices[i] - 1;

		// 考试
		if (i == last_t[idx]) {
		  if (nums[idx] > cnt) { // 没时间复习
			return false;
		  }

		  cnt -= nums[idx]; // 复习这门课
		} else {
		  ++cnt; // 留着后面用
		}
	  }

	  return true;
	};

	int left = n - 1, right = m - 1;
	int ans = -2;
	while (left <= right) {
	  int mid = (left + right) / 2;

	  // mid + 1 才是 完成所有目标的天数
	  if (check(mid + 1)) {
		ans = mid;
		right = mid - 1;
	  } else {
		left = mid + 1;
	  }
	}

	return ans + 1;
  }
};
