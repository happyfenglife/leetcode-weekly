#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static int minimumDeletions(string &word, int k) {
	int cnt[26]{};
	for (char c : word) {
	  cnt[c - 'a']++;
	}

	ranges::sort(cnt);

	int max_save = 0;
	for (int i = 0; i < 26; ++i) {
	  int sum = 0;

	  for (int j = i; j < 26; ++j) {
		sum += min(cnt[j], cnt[i] + k); // 至多保留 cnt[i]+k 个
	  }

	  max_save = max(max_save, sum);
	}

	return word.length() - max_save;
  }
};
