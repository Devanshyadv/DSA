#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<int> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int m = d; m <= mx; m += d) {
                cnt[d] += freq[m];
            }
        }

        // exactPairs[d] = pairs whose gcd is exactly d
        vector<long long> exactPairs(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long total = 1LL * cnt[d] * (cnt[d] - 1) / 2;

            for (int m = 2 * d; m <= mx; m += d) {
                total -= exactPairs[m];
            }

            exactPairs[d] = total;
        }

        // prefix[d] = pairs with gcd <= d
        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            prefix[d] = prefix[d - 1] + exactPairs[d];
        }

        vector<int> ans;
        for (long long q : queries) {
            int g = lower_bound(prefix.begin() + 1, prefix.end(), q + 1) - prefix.begin();
            ans.push_back(g);
        }

        return ans;
    }
};