from collections import Counter


class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        cnt = sorted(Counter(word).values())
        max_save = max(sum(min(c, base + k) for c in cnt[i:])
                       for i, base in enumerate(cnt))

        return len(word) - max_save
