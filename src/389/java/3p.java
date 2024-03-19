import java.util.Arrays;

public class Solution {
    public static int minimumDeletions(String word, int k) {
        int[] cnt = new int[26];
        for (char c : word.toCharArray()) {
            cnt[c - 'a']++;
        }
        Arrays.sort(cnt);

        int maxSave = 0;
        for (int i = 0; i < 26; i++) {
            int sum = 0;

            for (int j = i; j < 26; j++) {
                sum += Math.min(cnt[j], cnt[i] + k);
            }

            maxSave = Math.max(maxSave, sum);
        }

        return word.length() - maxSave;
    }
}