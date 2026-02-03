class Solution {
public:
    bool isTrionic(vector<int>& num) {
        int n = num.size();
        if (n < 3) return false;

        int i = 0;

        while (i + 1 < n && num[i] < num[i + 1]) i++;
        if (i == 0 || i == n - 1) return false;

        int p = i;
        while (i + 1 < n && num[i] > num[i + 1]) i++;
        if (i == p || i == n - 1) return false;

        
        int q = i;
        while (i + 1 < n && num[i] < num[i + 1]) i++;

        return i == n - 1;
    }
};