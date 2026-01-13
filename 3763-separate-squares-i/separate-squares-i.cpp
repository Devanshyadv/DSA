class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long double totalArea = 0;
        long double low = 1e18, high = -1e18;

        // Compute total area and search range
        for (auto &s : squares) {
            long double y = s[1];
            long double l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        long double target = totalArea / 2.0;

        
        for (int i = 0; i < 70; i++) {
            long double mid = (low + high) / 2.0;
            long double areaBelow = 0;

            for (auto &s : squares) {
                long double y = s[1];
                long double l = s[2];
                long double top = y + l;

                if (mid <= y) continue;
                else if (mid >= top) areaBelow += l * l;
                else areaBelow += l * (mid - y);
            }

            if (areaBelow >= target)
                high = mid;
            else
                low = mid;
        }

        return (double)low;
    }
};
