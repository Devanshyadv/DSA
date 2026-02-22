class Solution {
public:
    int binaryGap(int n) {
        vector<int> bin;

        while (n > 0) {
            bin.push_back(n % 2);
            n /= 2;
        }

        reverse(bin.begin(), bin.end());

        int last = -1;
        int ans = 0;

        for (int i = 0; i < bin.size(); i++) {
            if (bin[i] == 1) {
                if (last != -1)
                    ans = max(ans, i - last);
                last = i;
            }
        }
        return ans;
    }
};