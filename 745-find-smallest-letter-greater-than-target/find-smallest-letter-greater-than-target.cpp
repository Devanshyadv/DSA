class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char c : letters) {
            if (c > target) {
                return c;
            }
        }
        // wrap-around case
        return letters[0];
    }
};
