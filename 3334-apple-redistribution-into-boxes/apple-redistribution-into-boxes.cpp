class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApples = 0;
        for (int a : apple) totalApples += a;

        sort(capacity.begin(), capacity.end(), greater<int>());

        int usedCapacity = 0;
        int count = 0;

        for (int c : capacity) {
            usedCapacity += c;
            count++;
            if (usedCapacity >= totalApples)
                return count;
        }

        return -1; // if not enough capacity
    }
};
