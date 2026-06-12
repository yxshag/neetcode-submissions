class Solution {
public:
    int characterReplacement(string s, int k) {
    unordered_map<char, int> m;
    int maxf= 0, left = 0, result = 0;

    for (int right = 0; right < s.size(); right++) {
        m[s[right]]++;
        maxf = max(maxf, m[s[right]]);

        // window size - most frequent char = replacements needed
        while ((right - left + 1) - maxf > k) {
            m[s[left]]--;
            left++;
        }

        result = max(result, right - left + 1);
    }
    return result;
}
};
