#include <bits/stdc++.h>

using namespace std;

// 题目链接: https://leetcode.cn/problems/distribute-elements-into-two-arrays-ii/description/
class Fenwick {
  vector<int> tree;

 public:
  Fenwick(int n)
	  : tree(n) {

  }

  // 把下标为 i 的元素增加 1
  void add(int i) {
	while (i < tree.size()) {
	  tree[i]++;
	  i += lowbit(i);
	}
  }

  // 返回下标在 [1,i] 的元素之和
  int pre(int i) {
	int res = 0;
	while (i > 0) {
	  res += tree[i];
	  i -= lowbit(i);
	}

	return res;
  }

  int lowbit(int i) {
	return i & (-i);
  }
};

class Solution {
 public:
  vector<int> resultArray(vector<int> &nums) {
	auto sorted = nums;
	ranges::sort(sorted);
	int m = sorted.size();

	vector<int> a{nums[0]}, b{nums[1]};
	Fenwick t1(m + 1), t2(m + 1);
	t1.add(ranges::lower_bound(sorted, nums[0]) - sorted.begin() + 1);
	t2.add(ranges::lower_bound(sorted, nums[1]) - sorted.begin() + 1);

	for (int i = 2; i < nums.size(); ++i) {
	  int x = nums[i];
	  int v = ranges::lower_bound(sorted, x) - sorted.begin() + 1;
	  int gc1 = a.size() - t1.pre(v);
	  int gc2 = b.size() - t2.pre(v);

	  if (gc1 > gc2 || (gc1 == gc2 && a.size() <= b.size())) {
		a.push_back(x);
		t1.add(v);
	  } else {
		b.push_back(x);
		t2.add(v);
	  }
	}

	a.insert(a.end(), b.begin(), b.end());
	return a;
  }
};

auto __FAST_IO__ = []() noexcept {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  return 0;
};
