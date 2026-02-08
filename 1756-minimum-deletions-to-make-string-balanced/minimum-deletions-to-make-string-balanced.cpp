class Solution {
public:
    int minimumDeletions(string s) {
         int n = s.size();
        vector<int> dp(n + 1, 0);

        int a_count = 0;
        
        for (char c : s) {
            if (c == 'a') {
                a_count++;
            }
        }

        int min_deletions = a_count;
        int b_count = 0;

        for (int i = 0; i < n; ++i) {
            if (s[i] == 'b') {
                b_count++;
            } else {
                a_count--;
            }
            min_deletions = min(min_deletions, b_count + a_count);
        }

        return min_deletions;
    }
};